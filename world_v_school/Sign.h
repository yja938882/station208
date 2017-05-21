#pragma once
#ifndef SIGN_H
#define SIGN_H
#include "ofImage.h"

#define SIGN_WIDTH 120
#define SIGN_HEIGHT 120


class Sign
{
private:
	ofImage *images;
	int draw_index = 0;
	int img_max = 0;
	int img_index = 0;
	int posx[6];
	int posy[6];
	
public:
	Sign();
	~Sign();
	void setPos(int index,int x, int y);
	void allocImages(int size);
	void addImages(ofImage img);
	void draw();
};


#endif
