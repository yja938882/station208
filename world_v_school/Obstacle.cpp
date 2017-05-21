#include "Obstacle.h"



Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

void Obstacle::setUse(bool u) {
	use = u;
}
void Obstacle::setVisible(bool v) {
	visible = v;
}

void Obstacle::setSize(int w, int h) {
	width = w;
	height = h;
}

void Obstacle::allocImages(int size) {
	images = new ofImage[size];
	img_max = size;
}

void Obstacle::addImages(ofImage img) {
	if (img_index >= img_max)return;
	images[img_index++] = img;
}

void Obstacle::draw() {
	if (!visible)return;
	images[draw_index].draw(getPosition().x, getPosition().y, width, height);
}

