#include "Sign.h"



Sign::Sign()
{
}


Sign::~Sign()
{
}


void Sign::allocImages(int size) {
	images = new ofImage[size];
	img_max = size;
}

void Sign::addImages(ofImage img) {
	if (img_index >= img_max)return;
	images[img_index++] = img;
}

void Sign::setPos(int index,int x, int y) {
	posx[index] = x;
	posy[index] = y;
}

void Sign::draw() {
	for (int i = 0; i < 6; i++) {
		images[i].draw(posx[i], posy[i], SIGN_WIDTH, SIGN_HEIGHT);
	}
}

