#include "Temple.h"



Temple::Temple()
{
}


Temple::~Temple()
{
}

void Temple::update() {
	if (house_fire) {

	}
}
void Temple::drawHouseFire() {

}
void Temple::drawEffect() {
	if (!bullet.draw_effect)return;
	ofSetColor(255, 255, 224,90);
	ofFill();
	ofTriangle(getPosition().x+TEMPLE_WIDTH/2, getPosition().y+TEMPLE_HEIGHT/2, 800, 1920, 1080, 2300);
	ofTriangle(1080, 1920, 800, 1920, 1080, 2300);


	ofTriangle(getPosition().x + TEMPLE_WIDTH / 2, getPosition().y + TEMPLE_HEIGHT / 2, 0, 2000, 200, 1920);
	ofTriangle(0, 1920, 0, 2000, 200, 1920);

	ofTriangle(getPosition().x + TEMPLE_WIDTH / 2, getPosition().y + TEMPLE_HEIGHT / 2, 0, 1920+1000, 300, 1920*2);
	ofTriangle(0, 1920*2, 0, 1920 + 1000, 300, 1920 * 2);

	ofTriangle(getPosition().x + TEMPLE_WIDTH / 2, getPosition().y + TEMPLE_HEIGHT / 2, 900, 1920 * 2, 1080, 1920 + 1800);
	ofTriangle(1080, 1920*2, 900, 1920 * 2, 1080, 1920 + 1800);

	ofTriangle(getPosition().x + TEMPLE_WIDTH / 2, getPosition().y + TEMPLE_HEIGHT / 2, 1080, 1920 +900, 1080, 1920 + 1200);
//	ofCircle(getPosition().x + TEMPLE_WIDTH / 2, getPosition().y + TEMPLE_HEIGHT / 2, 100);

	ofSetHexColor(0xffffff);
}