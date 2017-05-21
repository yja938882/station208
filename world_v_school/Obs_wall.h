#pragma once
#ifndef OBS_WALL_H
#define OBS_WALL_H
#include "Obstacle.h"

#define OBS_2_WIDTH 300
#define OBS_2_HEIGHT 200
#define OBS_2_DEF_X 1283
#define OBS_2_DEF_Y 610
class Obs_wall : public Obstacle
{
private:
	int subx = 0;
	int suby = 0;
	int subw = OBS_2_WIDTH;
	int subh = OBS_2_HEIGHT;
	int effect_tic = 0;
public:

	Obs_wall();
	~Obs_wall();
	bool draw_effect = false;

	bool updateObs();
	void drawEffect();
	void drawObs();
	void play();
	void resetSubInfo();
};

#endif