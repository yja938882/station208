#include "Obs_wall.h"



Obs_wall::Obs_wall()
{
}


Obs_wall::~Obs_wall()
{
}
bool Obs_wall::updateObs() {
	if (!draw_effect)return false;

	suby++;
	//subw--;
	subh--;
	if (subh <= 5) {
		draw_effect = false;
		return true;
	}
	return false;
}
void Obs_wall::drawEffect() {
	images[draw_index].drawSubsection(OBS_2_DEF_X + subx, OBS_2_DEF_Y + suby, subw, subh, subx, suby);
}

void Obs_wall::drawObs() {
	if (visible)
		draw();
	if (draw_effect)
		drawEffect();
}

void Obs_wall::play() {
	visible = false;
	draw_effect = true;
}
void Obs_wall::resetSubInfo() {
	subx = 0;
	suby = 0;
	subw = OBS_2_WIDTH;
	subh = OBS_2_HEIGHT;
}