#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
}

void Character::allocImages(int type, int size) {
	switch (type) {
	case CHARACTER_CRY:
		cryImages = new ofImage[size];
		cry_img_max = size;
		break;
	case CHARACTER_WALK:
		walkImages = new ofImage[size];
		walk_img_max = size;
		break;
		/*
	case CHARACTER_IDLE:
		idleImages = new ofImage[size];
		idle_img_max = size;
		break;
		*/
	default:
		break;
	}
}

void Character::addImages(int type, ofImage img) {
	switch (type) {
	case CHARACTER_CRY:
		if (cry_img_index >= cry_img_max) {
			errorMsg("addImags overflow");
			return;
		}
		cryImages[cry_img_index++] = img;
		break;
	case CHARACTER_WALK:
		if (walk_img_index >= walk_img_max) {
			errorMsg("addImags overflow");
			return;
		}
		walkImages[walk_img_index++] = img;
		break;
		/*
	case CHARACTER_IDLE:
		if (idle_img_index >= idle_img_max) {
			errorMsg("addImags overflow");
			return;
		}
		idleImages[idle_img_index++] = img;
		break;
		*/
	default:
		break;
	}
}
void Character::setImages(int type,int i, ofImage img) {
	switch (type) {
	case CHARACTER_CRY:
		cryImages[i] = img;
		break;
	case CHARACTER_WALK:
		walkImages[i] = img;
		break;
	default:
		break;
	}
}

void Character::draw() {
	if (draw_item1) {
		itemImages[1].draw(getPosition().x , getPosition().y - 50, 180, 180);
	}

	ofPushMatrix();
	float rtx = 0;
	if (direction ==CHARACTER_LEFT) {
		rtx = getPosition().x + CHARACTER_WIDTH / 2;
		ofTranslate(rtx, 0);
		ofRotate(180, 0, 1, 0);
		
	}

	

	switch (state) {
	case CHARACTER_CRY:
		cryImages[cry_draw_index].draw(getPosition().x-rtx, getPosition().y,
			CHARACTER_WIDTH, CHARACTER_HEIGHT);
		break;
	case CHARACTER_WALK:
		walkImages[walk_draw_index].draw(getPosition().x-rtx, getPosition().y,
			CHARACTER_WIDTH, CHARACTER_HEIGHT);
		break;
		
	case CHARACTER_IDLE:
		walkImages[0].draw(getPosition().x-rtx, getPosition().y,
			CHARACTER_WIDTH, CHARACTER_HEIGHT);
		break;
		
	case CHARACTER_JUMP:
		walkImages[2].draw(getPosition().x - rtx, getPosition().y,
			CHARACTER_WIDTH, CHARACTER_HEIGHT);
		break;
	case CHARACTER_FLY:
		walkImages[2].draw(getPosition().x - rtx, getPosition().y,
			CHARACTER_WIDTH, CHARACTER_HEIGHT);
		break;
	}
	ofPopMatrix();
	bub.draw(getPosition().x-90, getPosition().y - 150);
	if (draw_item0) {
		itemImages[0].draw(getPosition().x, getPosition().y-70);
	}
	
	
}

void Character::update() {
	switch (state) {
	case CHARACTER_CRY:
		bub.moving = false;
		setVelocity(0, 0);
		tick++;
		if (tick <= CHARACTER_CRY_CM_0) {
			cry_draw_index = 0;
		}
		else if ((tick > CHARACTER_CRY_CM_0 && tick <= CHARACTER_CRY_CM_1) ||
			(tick > CHARACTER_CRY_CM_4  && tick <= CHARACTER_CRY_CM_5)) {
			cry_draw_index = 1;
		}
		else if ((tick > CHARACTER_CRY_CM_1 && tick <= CHARACTER_CRY_CM_2)||
			(tick > CHARACTER_CRY_CM_3  && tick <= CHARACTER_CRY_CM_4) ){
			cry_draw_index = 2;
		}
		else if (tick > CHARACTER_CRY_CM_2 && tick <= CHARACTER_CRY_CM_3) {
			cry_draw_index = 3;
		}
		else {
			tick = 0;
		}
		break;
	case CHARACTER_WALK:
		bub.moving = true;
		if (direction == CHARACTER_RIGHT) {
			if (op_index <= 4)
				setVelocity((path0_end - path0_start) / 350);
			if (op_index >= 8)
				setVelocity((path2_end - path2_start)/350);
		}
		else if (direction == CHARACTER_LEFT) {
			if(op_index>=5)
				setVelocity((path1_start - path1_end) / 350);
			if (op_index >= 11)
				setVelocity((path3_start - path3_end) / 350);
		}
		
		tick++;
		if (tick <= CHARACTER_WALK_CM_0) {
			walk_draw_index = 0;
		}
		else if ((tick > CHARACTER_WALK_CM_0&&tick <=CHARACTER_WALK_CM_1)||
					(tick > CHARACTER_WALK_CM_2 && tick <=CHARACTER_WALK_CM_3)) {
			walk_draw_index = 1;
		}
		else if ((tick > CHARACTER_WALK_CM_1&&tick <= CHARACTER_WALK_CM_2)||
			(tick>CHARACTER_WALK_CM_3 && tick <=CHARACTER_WALK_CM_4)) {
			walk_draw_index = 2;
		}
		else {
			tick = 0;
		}
		break;
	case CHARACTER_IDLE:
		setVelocity(0, 0);
		break;
	case CHARACTER_JUMP:
		if (getPosition().y >= jump_max_y && !jump_down) {
			setVelocity(0, -7);
			if (getPosition().y - jump_max_y <= 5) {
				jump_down = true;
			}
		}
		else if (getPosition().y <= jump_dest_y&&jump_down) {
			setVelocity(0, 7);
			if (jump_dest_y - getPosition().y <= 5) {
				jump_down = false;
				jump_end = true;
				nextOperation();
			}
		}
		break;
	case CHARACTER_FLY:
		//std::cout << "FLY!!\n";
		if (getPosition().y >= fly_up_dest_y && !fly_down) {
			setVelocity(0, -7);
		}
		else if(getPosition().x>=fly_up_dest_x){
			setVelocity(-4, 0);
			fly_down = true;
		}
		else if (getPosition().y <= fly_down_dest_y+3 && fly_down) {
			setVelocity(0, 7);
		}else {
			nextOperation();
		}
		break;
	}
	bub.update();
	
}

void Character::errorMsg(string text) {
	std::cout << "#> [ERROR] " + tag + " :" + text+"\n";
}

void Character::nextOperation() {
	tick = 0;
	int idle_draw_imdex = 0;
	int walk_draw_index = 0;
	int cry_draw_index = 0;
	std::cout << "OPCODE : " + to_string(op_index + 1)+"\n";
	//if (op_index == 17)
		//op_index = 0;
	switch (OP_SET[op_index++]) {
	case OP_CRY_R:
		state = CHARACTER_CRY;
		direction = CHARACTER_RIGHT;
		break;
	case OP_CRY_L:
		state = CHARACTER_CRY;
		direction = CHARACTER_LEFT;
		break;
	case OP_IDLE_R:
		state = CHARACTER_IDLE;
		direction = CHARACTER_RIGHT;
		break;
	case OP_IDLE_L:
		state = CHARACTER_IDLE;
		direction = CHARACTER_LEFT;
		break;
	case OP_WALK_R:
		state = CHARACTER_WALK;
		direction = CHARACTER_RIGHT;
		break;
	case OP_WALK_L:
		state = CHARACTER_WALK;
		direction = CHARACTER_LEFT;
		break;
	case OP_JUMP_L:
		state = CHARACTER_JUMP;
		direction = CHARACTER_LEFT;
		break;
	case OP_FLY_L:
		state = CHARACTER_FLY;
		direction = CHARACTER_LEFT;
		break;
	}
}

void Character::setItemImg(ofImage umbImg, ofImage balimg) {
	itemImages[0] = umbImg;
	itemImages[1] = balimg;
}
void Character::setNext() {
	op_index = 0;
	jump_down = false;
	jump_end = false;
	fly_down = false;
	bub.resetBubIndex();
	nextOperation();
	
}