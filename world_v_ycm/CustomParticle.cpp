#include "CustomParticle.h"



CustomParticle::CustomParticle()
{
}


CustomParticle::~CustomParticle()
{
}

void CustomParticle::drawImage() {
	float dig = getRotation();
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y);
	ofRotate(dig);
	image.draw(-width/2, -height/2, width, height);
	ofPopMatrix();


}

void CustomParticle::setImage(ofImage img, int w, int h, int r) {
	image = img;
	width = w;
	height = h;
	rad = r;

}
