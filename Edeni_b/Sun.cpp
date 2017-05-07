#include "Sun.h"


Sun::Sun()
{
}


Sun::~Sun()
{
}

void Sun::update() {
	blink_counter++;
	if (blink_counter >= BLINK_COUNT) {
		blink_counter = 0;
		if (draw_img_index == 0) {
			draw_img_index = 1;
		}
		else {
			draw_img_index = 0;
		}
	}
	mane_deg += 0.5;
	if (mane_deg >= 360.0)
		mane_deg = 0.0;
}
void Sun::setmaneImg(ofImage img) {
	maneImg = img;
}
void Sun::drawMane() {
	if (!day)return;

	ofPushMatrix();
	float tx = getPosition().x + SUN_WIDTH / 2;
	float ty = getPosition().y + SUN_HEIGHT / 2;
	ofTranslate(tx, ty);
	ofRotate(mane_deg, 0, 0, 1);
	maneImg.draw(getPosition().x - tx, getPosition().y - ty);
	ofPopMatrix();
}