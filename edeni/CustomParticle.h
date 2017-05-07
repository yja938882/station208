#pragma once
#ifndef CUSTOM_PARTICLE_H
#define CUSTOM_PARTICLE_H

#include "ofxBox2d.h"

class CustomParticle : public ofxBox2dRect
{
protected:
	int img_max;
	int img_index = 0;

public:
	ofImage *images;
	int draw_img_index = 0;

	CustomParticle();
	~CustomParticle();
	void allocImages(int size);
	void addImages(ofImage img);
	void setImages(ofImage img, int index);
	void draw();
	void draw(int, int);

};

#endif

