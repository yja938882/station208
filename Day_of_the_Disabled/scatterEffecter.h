#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
class scatterEffecter : public ofxBox2dRect {

public:
	ofImage img;
	int posX, posY;

	int w, h;

	bool tagged = false;


	bool yoyo = false;
	int yoyo_count = 0;
	int basic_w, basic_h;


	float shake_deg = 0.0;


	bool writing_p = false;


	bool show = false;


	scatterEffecter();
	~scatterEffecter();
	void setImage(ofImage img);
	void draw();

	float getBottomY();
	float getX();
};
