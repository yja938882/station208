#pragma once
#ifndef SUN_H
#define SUN_H
#include "CustomParticle.h"


#define SUN_WIDTH 300
#define SUN_HEIGHT 300

#define BLINK_COUNT 400
class Sun :public CustomParticle {
private:
	/*about blink*/
	int blink_counter = 0;

	/*abour mane*/
	ofImage maneImg;
	float mane_deg = 0.0;

	

public:
	bool day = true;
	Sun();
	~Sun();
	void update();
	void setmaneImg(ofImage img);
	void drawMane();
};
#endif