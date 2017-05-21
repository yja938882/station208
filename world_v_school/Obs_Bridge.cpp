#include "Obs_Bridge.h"



Obs_Bridge::Obs_Bridge()
{
}


Obs_Bridge::~Obs_Bridge()
{
}

bool Obs_Bridge::updateObs() {
	if (!draw_effect)return false;

	//subx++;
	subw++;
	if (subw >= OBS_3_WIDTH-5) {
		draw_effect = false;
		visible = true;
		return true;
	}
	return false;
}
void Obs_Bridge::drawEffect() {
	images[draw_index].drawSubsection(OBS_3_DEF_X, OBS_3_DEF_Y, subw, subh, subx, suby);
}

void Obs_Bridge::drawObs() {
	if (visible)
		draw();
	if (draw_effect)
		drawEffect();
}

void Obs_Bridge::play() {
	//visible = false;
	draw_effect = true;
}
void Obs_Bridge::resetSubInfo() {
	subx = 0;
	suby = 0;
	subw = 0;
	subh = OBS_3_HEIGHT;
}