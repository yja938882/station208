#pragma once
#ifndef OBS_RAIN_H
#define OBS_RAIN_H

#define OBS_4_WIDTH 400
#define OBS_4_HEIGHT 400
#define OBS_4_DEF_X 1320
#define OBS_4_DEF_Y 15

#include "Obstacle.h"
class Obs_rain : public Obstacle
{
public:
	int thunX[3] = {0, 150, 250
};
	int thunY[3] = { 0,0,0 };
		;
		int thun_tick=0;
public:
	Obs_rain();
	~Obs_rain();

	bool draw_effect = true;

	bool updateObs();
	void drawEffect();
	void drawObs();
	void play();


};

#endif