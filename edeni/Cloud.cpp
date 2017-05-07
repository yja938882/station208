#include "Cloud.h"

Cloud::Cloud()
{
}


Cloud::~Cloud()
{
}

void Cloud::update() {
	if (getPosition().x + CLOUD_WIDTH <= 0) {
		setPosition(1080, getPosition().y);
		setVelocity(-1 + ofRandom(-0.5, 0.5), 0);
	}
}
