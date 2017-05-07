#include "Angel.h"



Angel::Angel()
{
}


Angel::~Angel()
{
}

void Angel::update() {
	wing_deg += wing_df_deg;
	if (wing_deg >= 10.0)
		wing_df_deg = (-wing_df_deg);
	if (wing_deg <= -10.0)
		wing_df_deg = (-wing_df_deg);


}

void Angel::setWingImg(ofImage left, ofImage right) {
	leftwingImg = left;
	rightwingImg = right;
}

void Angel::drawWing() {

	/* left wing rotation*/
	ofPushMatrix();
	float ltx = getPosition().x + ANGEL_WING_WIDTH;
	float lty = getPosition().y + ANGEL_WING_HEIGHT + ANGEL_HEIGHT / 2;
	ofTranslate(ltx, lty);
	ofRotate(wing_deg, 0, 0, 1);
	leftwingImg.draw(getPosition().x - ltx, getPosition().y + ANGEL_HEIGHT / 2 - lty);
	ofPopMatrix();

	/*right wing rotation*/
	ofPushMatrix();
	float rtx = getPosition().x + ANGEL_WIDTH / 2;
	float rty = getPosition().y + ANGEL_WING_HEIGHT + ANGEL_HEIGHT / 2;
	ofTranslate(rtx, rty);
	ofRotate(-wing_deg, 0, 0, 1);
	rightwingImg.draw(getPosition().x - rtx + ANGEL_WIDTH / 2, getPosition().y + ANGEL_HEIGHT / 2 - rty);

	ofPopMatrix();
}
void Angel::drawBottomWing() {

	/* left wing rotation*/
	ofPushMatrix();
	float ltx = getPosition().x + bottom_wing_width;
	float lty = getPosition().y + bottom_wing_height + bottom_angel_height / 2;
	ofTranslate(ltx, lty);
	ofRotate(wing_deg, 0, 0, 1);
	leftwingImg.draw(getPosition().x - ltx, getPosition().y + bottom_angel_height / 2 - lty, bottom_wing_width, bottom_wing_height);
	ofPopMatrix();

	/*right wing rotation*/
	ofPushMatrix();
	float rtx = getPosition().x + bottom_angel_width / 2;
	float rty = getPosition().y + bottom_wing_height + bottom_angel_height / 2;
	ofTranslate(rtx, rty);
	ofRotate(-wing_deg, 0, 0, 1);
	rightwingImg.draw(getPosition().x - rtx + bottom_wing_width / 2 + 10, getPosition().y + bottom_angel_height / 2 - rty, bottom_wing_width, bottom_wing_height);

	ofPopMatrix();
}
void Angel::drawBottom() {
	images[draw_img_index].draw(getPosition().x, getPosition().y, bottom_angel_width, bottom_angel_height);
}

void Angel::setBottomAngel(float w, float h, float ww, float wh) {
	bottom_angel_width = w;
	bottom_angel_height = h;
	bottom_wing_height = wh;
	bottom_wing_width = ww;

}
void Angel::gotoDest(int destx, int desty) {
	float sx = 0.0;
	float sy = 0.0;
	if (abs(destx - getPosition().x) > 0.0) {
		sx = (destx - getPosition().x) / ANGEL_MOVE_TIC;
	}
	if (abs(desty - getPosition().y) > 0.0) {
		sy = (desty - getPosition().y) / ANGEL_MOVE_TIC;
	}
	setVelocity(sx, sy);
}