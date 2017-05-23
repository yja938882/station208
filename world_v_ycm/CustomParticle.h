#pragma once
#ifndef CUSTOM_PARTICLE_H
#define CUSTOM_PARTICLE_H

#include "ofxBox2d.h"
#include "ofMath.h"
#define PAD_W 200 
#define PAD_H 200 
#define PAD_R 65
#define PAD_IDLE_MAX 200

#define IDLE_MAX 200

class CustomParticle :public ofxBox2dCircle
{
private:
	int width;
	int height;
	int rad;
	int idle_count = IDLE_MAX;
	float idle_dig = 0.0;

public:
	ofImage image;
	bool idle_end = false;
	CustomParticle();
	~CustomParticle();
	void drawImage();
	void setImage(ofImage img, int w, int h, int r);

};

#endif