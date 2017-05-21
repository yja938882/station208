#pragma once
#ifndef OBS_STONE_H
#define OBS_STONE_H
#define OBS_1_WIDTH 330
#define OBS_1_HEIGHT 150
#define OBS_1_DEF_X 980
#define OBS_1_DEF_Y 927-OBS_1_HEIGHT
#include "Obstacle.h"
class Obs_stone : public Obstacle
{
private :
	int subx = 0;
	int suby = 0;
	int subw= OBS_1_WIDTH;
	int subh = OBS_1_HEIGHT;
	int effect_tic = 0;
public:
	Obs_stone();
	~Obs_stone();
	bool draw_effect = false;

	bool updateObs();
	void drawEffect();
	void drawObs();
	void play();
	void resetSubInfo();
};

#endif

