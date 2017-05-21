#include "Obs_stone.h"



Obs_stone::Obs_stone()
{
}


Obs_stone::~Obs_stone()
{
}

bool Obs_stone::updateObs() {
	if (!draw_effect)return false;

	suby++;
	subh--;
	if (subh <= 5) {
		draw_effect = false;
		return true;
	}
	return false;
}
void Obs_stone::drawEffect() {
	images[draw_index].drawSubsection(OBS_1_DEF_X+subx, OBS_1_DEF_Y+suby, subw,subh , subx, suby);
}

void Obs_stone::drawObs() {
	if(visible)
		draw();
	if (draw_effect)
		drawEffect();
}

void Obs_stone::play() {
	visible = false;
	draw_effect = true;
}
void Obs_stone::resetSubInfo() {
	subx = 0;
	suby = 0;
	subw = OBS_1_WIDTH;
	subh = OBS_1_HEIGHT;
}