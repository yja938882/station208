#include "Obs_pad.h"



Obs_pad::Obs_pad()
{
}


Obs_pad::~Obs_pad()
{
}

void Obs_pad::play() {
	setVisible(true);

}
bool Obs_pad::updateObs() {
	if (!visible)return false;
	if (idle_tic <= OBS_0_MAX_IDLE) {
		idle_tic++;
		draw_effect = true;
		return false;
	}
	draw_effect = false;
	return gotoDest(destx, desty);
}
void Obs_pad::setDest(int dx, int dy) {
	destx = dx;
	desty = dy;
}
bool Obs_pad::gotoDest(int destx, int desty) {
	float sx = 0.0;
	float sy = 0.0;
	if (abs(destx - getPosition().x) > 0.0) {
		sx = (destx - getPosition().x) / OBS_0_MOVE_TIC;
	}
	if (abs(desty - getPosition().y) > 0.0) {
		sy = (desty - getPosition().y) / OBS_0_MOVE_TIC;
	}

	if (abs(destx - getPosition().x) < 3.0 && abs(desty - getPosition().y) < 3.0) {
		setVisible(false);
		return true;
	}
	else {
		setVelocity(sx, sy);
		return false;
	}
	
}
void Obs_pad::drawEffect() {
	ofSetColor(255, 255, 224, 90);
	ofFill();
	ofTriangle(getPosition().x + OBS_0_WIDTH / 2, getPosition().y + OBS_0_HEIGHT / 2,
				1600, 0,
				1920, 200);
	ofTriangle(1920, 0, 1600, 0, 1920, 200);


	ofTriangle(getPosition().x + OBS_0_WIDTH / 2, getPosition().y + OBS_0_HEIGHT / 2,
		700, 0,
		1100, 0);
	

	ofTriangle(getPosition().x + OBS_0_WIDTH / 2, getPosition().y + OBS_0_HEIGHT / 2,
		0,200,
		0, 500);
	

	ofTriangle(getPosition().x + OBS_0_WIDTH / 2, getPosition().y + OBS_0_HEIGHT / 2,
		600,1080,
		900,1080);

	ofTriangle(getPosition().x + OBS_0_WIDTH / 2, getPosition().y + OBS_0_HEIGHT / 2,
		1920, 900,
		1800, 1080);
	ofTriangle(1920, 1080, 1920, 900, 1800, 1080);

	ofSetHexColor(0xffffff);
}
void Obs_pad::drawObs() {
	if (draw_effect)
		drawEffect();
	draw();
}
void Obs_pad::resetIdleTic() {
	idle_tic = 0;
}