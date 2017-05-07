#pragma once
#ifndef HOUSE_H
#define HOUSE_H


#define HOUSE_MOVE_TIC 30.0
#include "CustomParticle.h"

#define HOUSE_TYPE_NUM 9

#define HOUSE_WIDTH 1080
#define HOUSE_HEIGHT 900
#define HOUSE_DEF_X 0
#define HOUSE_DEF_Y 620

#define HOUSE_BLOCK_START_Y -300
class House : public CustomParticle {
private:



public:

	House();
	~House();
	bool updateHouse();
	void cumDraw();
	bool upgrade();
	void resetDrawIndex();

	class HouseBlock :public CustomParticle{
	public :
		bool processing = false;
		bool visible = false;
		HouseBlock() {}
		~HouseBlock() {}
		bool updateBlock() {
			if (!processing) return false;

			if (getPosition().y < HOUSE_DEF_Y) {
				setVelocity(0, 6);
				return false;
			}
			else {
				setVelocity(0, 0);
				visible = false;
				processing = false;
				setPosition(0, HOUSE_BLOCK_START_Y);
				return true;
			}
		}
	};
	HouseBlock houseBlock;
};
#endif