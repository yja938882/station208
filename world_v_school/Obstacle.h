#pragma once
#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "ofxBox2D.h"
class Obstacle :public ofxBox2dRect
{
protected :
	bool use = true;
	bool visible = true;
	int draw_index = 0;
	int img_max = 0;
	int img_index = 0;
	int width = 0;
	int height = 0;
public:
	ofImage *images;
	Obstacle();
	~Obstacle();

	void setUse(bool u);
	void setVisible(bool v);
	void setSize(int width, int height);
	void allocImages(int size);
	void addImages(ofImage img);
	void draw();
};

#endif

/* 

Obstacle 1 : pad 
Obstacle 2 : stone
Obstacle 3 :


*/

