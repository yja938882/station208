#pragma once
#ifndef CLOUD_H
#define CLOUD_H
#include "CustomParticle.h"
#define CLOUD_HEIGHT 80
#define CLOUD_WIDTH 180
#define CLOUD_NUM 4

class Cloud : public CustomParticle {
public:
	Cloud();
	~Cloud();
	void update();
};

#endif