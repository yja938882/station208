#pragma once
#ifndef OBS_UMB_H
#define OBS_UMB_H

#define OBS_41_WIDTH 150
#define OBS_41_HEIGHT 190
#define OBS_41_MOVE_TIC 30.0
#define OBS_41_MAX_IDLE 100


#define OBS_41_DEF_X 1920/2 - OBS_41_WIDTH/2
#define OBS_41_DEF_Y 1080/2 - OBS_41_HEIGHT/2


#include "Obstacle.h"

class Obs_umb : public Obstacle
{
private:
	int destx;
	int desty;
	int idle_tic = 0;
	bool draw_effect = false;

public:
	Obs_umb();
	~Obs_umb();
	void play();
	bool updateObs();
	void setDest(int destx, int desty);
	void drawEffect();
	void drawObs();
	bool gotoDest(int destx, int desty);
	void resetIdleTic();
};

#endif