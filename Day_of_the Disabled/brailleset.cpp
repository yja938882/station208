#include "brailleset.h"
#include "ofMain.h"
#include "ofxBox2d.h"

brailleset::brailleset()
{
	
}


brailleset::~brailleset()
{
}
void brailleset::load_Brailles() {
	string path = "images/braille_";
	brailles = new ofImage[26];
	for (int i = 0; i < 26; i++) {
		brailles[i].load(path + (char)('a' + i) + ".png");
	}
}

ofImage* brailleset::getBraille(char c)
{
	return &brailles[c - 'a'];
}

