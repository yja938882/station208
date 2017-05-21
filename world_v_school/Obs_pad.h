#pragma once
#ifndef OBS_PAD_H
#define OBS_PAD_H



#define OBS_0_WIDTH 150
#define OBS_0_HEIGHT 150

#define OBS_0_DEF_X 1920/2 - OBS_0_WIDTH/2
#define OBS_0_DEF_Y 1080/2 - OBS_0_HEIGHT/2

#define OBS_0_MOVE_TIC 15.0
#define OBS_0_MAX_IDLE 100
#include "Obstacle.h"
class Obs_pad : public Obstacle
{
private:
	int destx;
	int desty;
	int idle_tic = 0;
	bool draw_effect = false;
public:
	Obs_pad();
	~Obs_pad();
	void play();
	bool updateObs();
	void setDest(int destx, int desty);
	void drawEffect();
	void drawObs();
	bool gotoDest(int destx, int desty);
	void resetIdleTic();
};

#endif

