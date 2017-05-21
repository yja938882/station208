#pragma once
#ifndef OBS_BRIDGE_H
#define OBS_BRIDGE_H
#include "Obstacle.h"

#define OBS_3_WIDTH 260
#define OBS_3_HEIGHT 160
#define OBS_3_DEF_X 477
#define OBS_3_DEF_Y 490

class Obs_Bridge : public Obstacle
{
private :
	int subx = 0;
	int suby = 0;
	int subw = 0;
	int subh = OBS_3_HEIGHT;
	int effect_tic = 0;
public:
	Obs_Bridge();
	~Obs_Bridge();
	bool draw_effect = false;

	bool updateObs();
	void drawEffect();
	void drawObs();
	void play();
	void resetSubInfo();
};

#endif

