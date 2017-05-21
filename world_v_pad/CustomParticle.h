#pragma once
#ifndef CUSTOM_PARTICLE_H
#define CUSTOM_PARTICLE_H

#include "ofxBox2d.h"
#include "ofMath.h"
//'1' means #of pad 
#define PAD_1_W 200 //width
#define PAD_1_H 200 //height
#define PAD_1_R 100 //radius
#define PAD_1_M 30 //margin
#define PAD_1_IDLE_MAX 200

#define PAD_1_DEF_X  1920 / 2
#define PAD_1_DEF_Y  1080
#define PAD_1_RAD 40

#define TAN_10 0.6483
#define TL 1500
#define DEG(x) (x)*(3.1416/180.0)
class CustomParticle :public ofxBox2dCircle
{
private:
	int width;
	int height;
	int rad;
	int idle_count=PAD_1_IDLE_MAX;
	float idle_dig = 0.0;
	
public:
	ofImage image;
	bool idle_end = false;
	CustomParticle();
	~CustomParticle();
	void drawImage();
	void setImage(ofImage img, int w , int h, int r);

};

#endif