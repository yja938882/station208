#include "Obs_bal.h"



Obs_bal::Obs_bal()
{
}


Obs_bal::~Obs_bal()
{
}

void Obs_bal::play() {
	setVisible(true);

}
bool Obs_bal::updateObs() {
	if (!visible)return false;
	if (idle_tic <= OBS_50_MAX_IDLE) {
		idle_tic++;
		draw_effect = true;
		return false;
	}
	draw_effect = false;
	return gotoDest(destx, desty);
}
void Obs_bal::setDest(int dx, int dy) {
	destx = dx;
	desty = dy;
}
bool Obs_bal::gotoDest(int destx, int desty) {
	float sx = 0.0;
	float sy = 0.0;
	if (abs(destx - getPosition().x) > 0.0) {
		sx = (destx - getPosition().x) / OBS_50_MOVE_TIC;
	}
	if (abs(desty - getPosition().y) > 0.0) {
		sy = (desty - getPosition().y) / OBS_50_MOVE_TIC;
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
void Obs_bal::drawEffect() {
	ofSetColor(255, 255, 224, 90);
	ofFill();
	ofTriangle(getPosition().x + OBS_50_WIDTH / 2, getPosition().y + OBS_50_HEIGHT / 2,
		1600, 0,
		1920, 200);
	ofTriangle(1920, 0, 1600, 0, 1920, 200);


	ofTriangle(getPosition().x + OBS_50_WIDTH / 2, getPosition().y + OBS_50_HEIGHT / 2,
		700, 0,
		1100, 0);


	ofTriangle(getPosition().x + OBS_50_WIDTH / 2, getPosition().y + OBS_50_HEIGHT / 2,
		0, 200,
		0, 500);


	ofTriangle(getPosition().x + OBS_50_WIDTH / 2, getPosition().y + OBS_50_HEIGHT / 2,
		600, 1080,
		900, 1080);

	ofTriangle(getPosition().x + OBS_50_WIDTH / 2, getPosition().y + OBS_50_HEIGHT / 2,
		1920, 900,
		1800, 1080);
	ofTriangle(1920, 1080, 1920, 900, 1800, 1080);

	ofSetHexColor(0xffffff);
}
void Obs_bal::drawObs() {
	if (draw_effect)
		drawEffect();
	draw();
}
void Obs_bal::resetIdleTic() {
	idle_tic = 0;
}