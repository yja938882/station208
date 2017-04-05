#include "scatterEffecter.h"



scatterEffecter::scatterEffecter()
{
}


scatterEffecter::~scatterEffecter()
{
}

void scatterEffecter::draw() {
	//ofPushMatrix();
	//float tposX = (float)20 / 2.0 + getPosition().x;
	//float tposY = (float)20 / 2.0 + getPosition().y;
	//ofTranslate(tposX, tposY, 0);
	//ofRotate(shake_deg, 0, 0, 1);
	img.draw(getPosition().x , getPosition().y , 40, 40);

	ofPopMatrix();

}

float scatterEffecter::getBottomY() {
	return posY + basic_h;
}
float scatterEffecter::getX() {
	return posX;
}
void scatterEffecter::setImage(ofImage img) {
	scatterEffecter::img = img;
}