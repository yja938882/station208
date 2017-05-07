#include "House.h"


House::House()
{
}


House::~House()
{
}

bool House::updateHouse() {
	//houseBlock.update();
	if (houseBlock.updateBlock()) {
		if (upgrade()) {
			//set NextHouse..
			return true;
		}
		else {
			houseBlock.setImages(images[draw_img_index + 1], 0);
		}
	}
	return false;
}

void House::cumDraw() {	
	for (int i = 0; i <= draw_img_index; i++) {
		images[i].draw(getPosition());
	}
}

bool House::upgrade() {
	draw_img_index++;
	if (draw_img_index >= img_max - 1) {
		return true;
	}
	return false;
}
void House::resetDrawIndex() {
	draw_img_index = 0;
}
