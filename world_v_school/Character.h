#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "ofxBox2d.h"
#include "ofxTrueTypeFontUC.h"

#define CHARACTER_HEIGHT 192
#define CHARACTER_WIDTH 150

//start Position
#define CHARACTER_DEF_X 350
#define CHARACTER_DEF_Y 997 - CHARACTER_HEIGHT

//direction
#define CHARACTER_RIGHT 0
#define CHARACTER_LEFT 1

//state
#define CHARACTER_CRY 0 //num : 4
#define CHARACTER_WALK 1
#define CHARACTER_IDLE 2
#define CHARACTER_JUMP 3
#define CHARACTER_FLY 4


//character type
#define CHARACTER_TYPE_0 0
#define CHARACTER_TYPE_1 1

//update max _CRY 
#define CHARACTER_CRY_CM_0 75
#define CHARACTER_CRY_CM_1 CHARACTER_CRY_CM_0+10
#define CHARACTER_CRY_CM_2 CHARACTER_CRY_CM_1+5
#define CHARACTER_CRY_CM_3 CHARACTER_CRY_CM_2+100
#define CHARACTER_CRY_CM_4 CHARACTER_CRY_CM_3+10
#define CHARACTER_CRY_CM_5 CHARACTER_CRY_CM_4+10

//update max _WALK
#define CHARACTER_WALK_CM_0 10
#define CHARACTER_WALK_CM_1 CHARACTER_WALK_CM_0 + 25
#define CHARACTER_WALK_CM_2 CHARACTER_WALK_CM_1 + 25
#define CHARACTER_WALK_CM_3 CHARACTER_WALK_CM_2 + 25 
#define CHARACTER_WALK_CM_4 CHARACTER_WALK_CM_3 + 25

#define CHARACTER_FLY_CM_0 100
#define CHARACTER_FLY_CM_1 CHARACTER_FLY_CM_0 +100
#define CHARACTER_FLY_CM_2 CHARACTER_FLY_CM_1 +100


//walkSpeed
#define CHARACTER_SPEED 1.0

//Operation
#define OP_CRY_R 0
#define OP_CRY_L 1
#define OP_IDLE_R 2
#define OP_IDLE_L 3
#define OP_WALK_R 4
#define OP_WALK_L 5
#define OP_JUMP_L 6
#define OP_FLY_L 7


class Character : public ofxBox2dRect
{
private :
	ofPoint path0_start = { 23.0, 1035.0 };
	ofPoint path0_end = { 1901.0, 831.0 };

	ofPoint path1_start = { 23.0 , 701.0 };
	ofPoint path1_end = { 1901.0 , 829.0 };

	ofPoint path2_start = { 23.0 , 701.0 };
	ofPoint path2_end = { 1901.0 , 487.0 };

	ofPoint path3_start = { 23.0, 412.0  };
	ofPoint path3_end = { 1901.0, 412.0 };

	string tag = "Character";
	/*
	//Image set
	ofImage *idleImages;
	int idle_img_index = 0;
	int idle_img_max = 0;
	int idle_draw_imdex=0;
	*/

	ofImage *walkImages;
	int walk_img_index = 0;
	int walk_img_max = 0;
	int walk_draw_index = 0;

	ofImage *cryImages;
	int cry_img_index = 0;
	int cry_img_max = 0;
	int cry_draw_index = 0;

	int jump_dest_y = 420-CHARACTER_HEIGHT;
	int jump_max_y = 412 - 50 - CHARACTER_HEIGHT;
	bool jump_down = false;
	bool jump_end = false;

	int fly_up_dest_y = 200 - CHARACTER_HEIGHT;
	bool fly_down = false;

	int fly_up_dest_x = 625;
	int fly_down_dest_y = 412 - CHARACTER_HEIGHT;

	int op_index=1;

	int OP_SET[18] = {
		OP_CRY_R,		OP_WALK_R,		OP_CRY_R,			OP_WALK_R,
		OP_WALK_L,		OP_CRY_L,    	OP_WALK_L,
		OP_WALK_R,		OP_CRY_R, 		OP_WALK_R,
		OP_JUMP_L,		OP_WALK_L,		OP_CRY_L,	OP_WALK_L,	OP_CRY_L,	OP_FLY_L,
		OP_WALK_L,		OP_IDLE_L
	};

	void errorMsg(string text);

	int direction =CHARACTER_RIGHT; // CHARACTER_RIGHT, CHARACTER_LEFT
	int state = CHARACTER_CRY;		// CHARACTER_CRY , CHARACTER_WALK, CHARACTER_IDLE
	int tick = 0;

	ofImage itemImages[2];


public:
	Character();
	~Character();
	
	void allocImages(int type,int size);
	void addImages(int type,ofImage img);
	void setImages(int type,int i, ofImage img);
	void draw();
	void update();
	void nextOperation();
	void setItemImg(ofImage umbImg, ofImage img);
	bool draw_item0 = false;
	bool draw_item1 = false;
	void setNext();
	
	class Bub {
	public:
		Bub() {}
		ofxTrueTypeFontUC font;
		ofImage img;
		string tankment = "\n    고마워!!";
		string obsment[4] = { 
			"생리대가 없어서 \n학교에 갈 수 없어 ㅠㅠ",
			"이걸 다 치워야 \n학교에 갈 수 있어 ㅠㅠ ",
			"여자라서 학교에 \n갈 수 없대...ㅠㅠ",
			"길이 없어서 \n학교에 갈 수 없어 ..ㅠㅠ "
		};
		int ment_index = 0;
		bool moving = false;
		bool show_thanks = false;
		int moving_str_index = 1;
		int ment_str_index = 1;
		void draw(int posx, int posy) {
			if(moving||show_thanks)
				img.draw(posx, posy,350,150);
			ofSetHexColor(0x000000);
			if (moving) {
				font.drawString(tankment.substr(0, moving_str_index), posx + 20, posy + 40);
			}
			if (show_thanks) {
				font.drawString(obsment[ment_index].substr(0,ment_str_index), posx + 20, posy + 40);
			}
			ofSetHexColor(0xffffff);
		}
		void upgrade() {
			ment_index++;
			if (ment_index >= 4)
				ment_index = 0;
		}
		void loadFont(){
			font.loadFont("font/chfont.ttf",20,true,true);
		}
		void resetBubIndex() {
			ment_index = 0;
		}
		void showMent() {
			ment_str_index = 1;
			show_thanks = true;
		}
		void closeMent() {
			show_thanks = false;
		}
		void showMoving() {
			moving_str_index = 1;
			moving = true;
		}
		void closeMoving() {
			moving = false;
		}
		void update() {
			if (moving) {
				if (moving_str_index < tankment.length())
					moving_str_index++;
			}
			if (show_thanks) {
				if (ment_str_index < obsment[ment_index].length())
					ment_str_index++;
			}
		}
	};
	Bub bub;
	
};

#endif

