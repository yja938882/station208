#pragma once
#ifndef OBS_CORC
#define COBS_CORC
#include "Obstacle.h"

#define OBS_5_WIDTH 190
#define OBS_5_HEIGHT 150
#define OBS_5_DEF_X 752
#define OBS_5_DEF_Y 419 - 150
#define OBS_5_RIGHT 0
#define OBS_5_LEFT 1

class Obs_corc : public Obstacle
{
private :
	int dx=0;
	int dy = 0;
	int subw=OBS_5_WIDTH;
	int subh=OBS_5_HEIGHT;
	int update_tic=0;
	int direction = OBS_5_LEFT;
public:
	Obs_corc();
	~Obs_corc();
	bool draw_effect = true;

	bool updateObs();
	void drawEffect();
	void drawObs();
	void play();
};

#endif