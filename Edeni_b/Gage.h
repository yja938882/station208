#pragma once
#ifndef GAGE_H
#define GAGE_H
#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
#define MAX 980
class Gage
{
public:
	ofImage gageImage;
	int PstartX;
	int PstartY;
	int Pwidth;
	int Pheight;
	int num = 0;

	ofxTrueTypeFontUC font;


	Gage();
	~Gage();
	void setGage();
	void draw();
	void upGage();
};


#endif