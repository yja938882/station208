#include "Gage.h"




Gage::Gage()
{
}


Gage::~Gage()
{
}
void Gage::setGage() {
	gageImage.load("images/gage.png");
	PstartX = 54;
	PstartY = 26;
	Pwidth = 1;
	Pheight = 47;
	font.loadFont("font/gagefont.ttf", 20, true, true);
}
void Gage::draw() {
	gageImage.draw(0, 0, 1080, 99);
	ofSetColor(255, 0, 102);
	ofFill();
	ofRect(PstartX, PstartY, Pwidth, Pheight);

	ofSetColor(ofColor::black);
	font.drawString("���ݱ��� " + to_string(num) + "���� �����ϼ̽��ϴ�.", 290, 120);
	ofSetColor(255);
}
void Gage::upGage() {
	float up = (float)MAX *((float)1.0 / 500.0);
	Pwidth += (int)up;
	num++;
}