#include "Obs_corc.h"



Obs_corc::Obs_corc()
{
}


Obs_corc::~Obs_corc()
{
}
bool Obs_corc::updateObs() {
	if (!draw_effect)return false;

	update_tic++;
	if (update_tic < 100) {// idle
	//	suby = 50;
		dy = 50;
		subh = OBS_5_HEIGHT - dy;
	}
	else if (update_tic >= 100 && update_tic < 200) {
		if (dy < 100) {
			dy++;
			subh = OBS_5_HEIGHT - dy;
		}

	}
	else if (update_tic >= 200 && update_tic < 300) {
		if (dy > 50) {
			dy--;
			subh = OBS_5_HEIGHT - dy;
		}
	}
	else if (update_tic == 300) {
		if (direction == OBS_5_LEFT) {
			direction = OBS_5_RIGHT;
		}
		else {
			direction = OBS_5_LEFT;
		}
	}
	else {
		update_tic = 0;
	}
	
	return false;
}
void Obs_corc::drawEffect() {
	ofPushMatrix();
	float rtx=0;
	if (direction == OBS_5_LEFT) {
		rtx = OBS_5_DEF_X + OBS_5_WIDTH / 2;
		ofTranslate(rtx, 0);
		ofRotate(180, 0, 1, 0);
	}
	images[draw_index].drawSubsection(OBS_5_DEF_X + dx - rtx, OBS_5_DEF_Y + dy, subw, subh, 0, 0);
	ofPopMatrix();
}

void Obs_corc::drawObs() {
	//if (visible)
		//draw();
	if (draw_effect)
		drawEffect();
}

void Obs_corc::play() {
	visible = false;
	draw_effect = true;
}