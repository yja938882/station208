#pragma once
#include "ofMain.h"
class brailleset
{
public:
	ofImage* brailles;
	brailleset();
	~brailleset();
	ofImage* getBraille(char c);
	void load_Brailles();
};

