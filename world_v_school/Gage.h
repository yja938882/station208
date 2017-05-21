#pragma once
#ifndef GAGE_H
#define GAGE_H
#include "ofImage.h"
#include "ofxTrueTypeFontUC.h"
#include "ofMain.h"
#define GAGE_DEF_X 1920-900
#define GAGE_DEF_Y 0
#define GAGE_MAX 500.0
#define GAGE_HEIGHT 100
#define GAGE_WIDTH 900.0
class Gage
{
private:
	int num = 0;
	ofImage gageFrame;
	ofImage gageBar;
	ofxTrueTypeFontUC font;
	ofImage ch_face;
public:
	Gage();
	~Gage();
	void setImg(ofImage bar, ofImage frame);
	void gageup();
	void fontSet();
	void draw(); 
	void setChFace(ofImage img);
};

#endif

