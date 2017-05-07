#ifndef ANGEL_H
#define ANGEL_H

#define ANGEL_WIDTH 200
#define ANGEL_HEIGHT 290
#define ANGEL_WING_WIDTH 100
#define ANGEL_WING_HEIGHT 50
#define ANGEL_MOVE_TIC 30.0

#define ANGEL_0_DEF_X 700
#define ANGEL_1_DEF_X 200

#define ANGEL_DEF_Y 1500

#include "CustomParticle.h"
#include <cmath>

class Angel :public CustomParticle
{
private:
	float wing_deg = 0.0;
	float wing_df_deg = 0.5;

	float bottom_wing_width;
	float bottom_wing_height;

	float bottom_angel_width;
	float bottom_angel_height;

	ofImage leftwingImg;
	ofImage rightwingImg;

	bool jumping = false;
	int jump_count = 0;
	float jump_speed = 20;
	float dif_jump_speed = 0.5;

	bool gotodest = false;

public:
	Angel();
	~Angel();
	void update();
	void setWingImg(ofImage left, ofImage right);
	void drawWing();
	void drawBottomWing();
	void drawBottom();
	void setBottomAngel(float w, float h, float ww, float wh);
	void gotoDest(int destx, int desty);
};

#endif