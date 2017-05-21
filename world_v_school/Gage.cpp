#include "Gage.h"



Gage::Gage()
{
}


Gage::~Gage()
{
}
void Gage::setImg(ofImage bar, ofImage frame) {
	gageBar = bar;
	gageFrame = frame;
}
void Gage::setChFace(ofImage img) {
	ch_face = img;
}
void Gage::gageup() {
	num++;
}
void Gage::draw() {
	float w = ((float)num/GAGE_MAX)*GAGE_WIDTH + 180.0;
	gageBar.drawSubsection(GAGE_DEF_X,GAGE_DEF_Y,w,GAGE_HEIGHT,0,0);
	gageFrame.draw(GAGE_DEF_X,GAGE_DEF_Y);
	ch_face.draw(GAGE_DEF_X + 100, GAGE_DEF_Y+10, GAGE_HEIGHT - 20, GAGE_HEIGHT - 20);

	ofSetHexColor(0xffffff);
	font.drawString(to_string(num) + "분이 서명해주셨습니다.",GAGE_DEF_X+200,GAGE_DEF_Y+55);
}
void Gage::fontSet() {
	font.loadFont("font/chfont.ttf", 18, true, true);
}
