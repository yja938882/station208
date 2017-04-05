#include "bookIr.h"



bookIr::bookIr()
{
}


bookIr::~bookIr()
{
}

void bookIr::draw() {
	img.draw(posX, posY, w, h);
	
	ofSetHexColor(0x000000);
	font3.drawString(title, posX + 600, posY + 600);
	ofSetHexColor(0x000000);
	font.drawString(page1, posX + 120, posY + 120);
	font.drawString(page2, posX + 120 + 500, posY + 120);
	if (p1_han)font2.drawString(ttohan,posX + 120, posY + 400);
	if (p2_han)font2.drawString(ttohan2, posX + 620, posY + 400);
	ofSetHexColor(0xffffff);
}
void bookIr::draw(int x, int y) {
	img.draw(posX+x, posY+y, w, h);
	//std::cout << "BOK DRAWind";
	ofSetHexColor(0x000000);
	//font.drawString(page1, posX+120, posY+120);
	//font.drawString(page2, posX + 120 + 500, posY + 120);
	font3.drawString(title, posX+x + 600, posY+y + 600);
	ofSetHexColor(0x000000);
	font.drawString(page1, posX+x + 120, posY+y + 120);
	font.drawString(page2, posX+x + 120 + 500, posY+y + 120);
	if (p1_han)font2.drawString(ttohan, posX+x + 120, posY+y + 400);
	if (p2_han)font2.drawString(ttohan2, posX+x + 620, posY+y + 400);
	ofSetHexColor(0xffffff);
}
void bookIr::draw(int x, int y, int a) {
	img.draw(posX + x, posY + y, w, h);
	//std::cout << "BOK DRAWind";
	ofSetColor(0,0,0,a);
	//font.drawString(page1, posX+120, posY+120);
	//font.drawString(page2, posX + 120 + 500, posY + 120);
	font3.drawString(title, posX + x + 600, posY + y + 600);
	font.drawString(page1, posX + x + 120, posY + y + 120);
	font.drawString(page2, posX + x + 120 + 500, posY + y + 120);
	if (p1_han)font2.drawString(ttohan, posX + x + 120, posY + y + 400);
	if (p2_han)font2.drawString(ttohan2, posX + x + 620, posY + y + 400);
	ofSetHexColor(0xffffff);
}


void bookIr::setPos(float x, float y, float width, float height) {
	posX = x;
	posY = y;
	w = width;
	h = height;
	page1 = "";
	page2 = "";
}

void bookIr::setImg() {
	img.load("images/book.png");
}
void bookIr::setFont() {
	font.loadFont("font/luc.ttf", 40, true, true);
	font.setLetterSpacing(0.8);

	font2.loadFont("font/mj.ttf", 28, true, true);
	font2.setLetterSpacing(1);

	font3.loadFont("font/mj.ttf", 24, true, true);
	font3.setLetterSpacing(1);
}
void bookIr::addString(string adds) {
	page1 += adds;
}
void bookIr::setString(string set) {
	page1 = set;
}
void bookIr::resetString() {
	p1_han = false;
	p2_han = false;
	page1 = "";
	page2 = "";
	title = "";
	ttohan = "";
	ttohan2 = "";
}
void bookIr::addString2(string adds) {
	page2 += adds;
}
void bookIr::setString2(string set) {
	page2 = set;
}
void bookIr::setTitle(string t) {
	title = t;
}
void bookIr::setHangle(string han) {
	ttohan = han;
}
void bookIr::setHangle2(string han) {
	ttohan2 = han;
}