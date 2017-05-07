#include "CustomParticle.h"



CustomParticle::CustomParticle()
{
}


CustomParticle::~CustomParticle()
{
}

//Alloc Images
void CustomParticle::allocImages(int size) {
	images = new ofImage[size];
	img_max = size;
}

//add Images
void CustomParticle::addImages(ofImage img) {
	if (img_index >= img_max)
		return;
	images[img_index++] = img;
}
void CustomParticle::setImages(ofImage img, int index) {
	images[index] = img;
}

//Draw Images
void CustomParticle::draw() {
	images[draw_img_index].draw(getPosition());
}

void CustomParticle::draw(int w, int h) {
	images[draw_img_index].draw(getPosition().x, getPosition().y, w, h);
}