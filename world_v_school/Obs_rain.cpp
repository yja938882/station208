#include "Obs_rain.h"



Obs_rain::Obs_rain()
{
}


Obs_rain::~Obs_rain()
{
}

bool Obs_rain::updateObs() {
	//if (!draw_effect)return false;

	thun_tick++;
	if (thun_tick < 60) { //Not draw Thunder
		draw_effect = false;
	}
	else if (thun_tick == 60) {
		for (int i = 0; i < 3; i++) {
			thunY[i] = (int)ofRandom(0, 180);
		}
		thunX[0] = (int)ofRandom(0, 100);
		thunX[1] = (int)ofRandom(150, 250);
		thunX[2] = (int)ofRandom(250, 350);
	}
	else if (thun_tick > 60 && thun_tick < 160) {
		draw_effect = true;
	}
	else {
		thun_tick = 0;
	}
	
	return false;
}
void Obs_rain::drawEffect() {
	for (int i = 0; i < 3; i++) {
		images[1].draw(OBS_4_DEF_X+thunX[i],OBS_4_DEF_Y+thunY[i]);
	}
	//images[draw_index].drawSubsection(OBS_2_DEF_X + subx, OBS_2_DEF_Y + suby, subw, subh, subx, suby);
}

void Obs_rain::drawObs() {
	if (visible)
		draw();
	if (draw_effect)
		drawEffect();
}

void Obs_rain::play() {
	visible = false;
	draw_effect = true;
}