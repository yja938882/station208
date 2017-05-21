#pragma once
#ifndef OBS_BAL_H
#define OBS_BAL_H

#define OBS_50_WIDTH 200
#define OBS_50_HEIGHT 200
#define OBS_50_MOVE_TIC 30.0
#define OBS_50_MAX_IDLE 100

#define OBS_50_DEF_X 1920/2 - OBS_41_WIDTH/2
#define OBS_50_DEF_Y 1080/2 - OBS_41_HEIGHT/2

#include "Obstacle.h"

class Obs_bal : public Obstacle
{
private:
	int destx;
	int desty;
	int idle_tic = 0;
	bool draw_effect = false;

public:
	Obs_bal();
	~Obs_bal();
	void play();
	bool updateObs();
	void setDest(int destx, int desty);
	void drawEffect();
	void drawObs();
	bool gotoDest(int destx, int desty);
	void resetIdleTic();
};


#endif