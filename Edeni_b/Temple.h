#pragma once
#ifndef TEMPLE_H
#define TEMPLE_H
#define TEMPLE_HEIGHT 400
#define TEMPLE_WIDTH 400
#define TEMPLE_DEF_X 300
#define TEMPLE_DEF_Y 1920+740
#define TEMPLE_BULLET_MOVE_TIC 30.0
#include "CustomParticle.h"
class Temple : public CustomParticle
{
public:
	ofImage housesImages[9];
	Temple();
	~Temple();
	void drawHouseFire();
	void update();
	bool house_fire = false;
	
	class Bullet : public CustomParticle{
	public:
		int destX;
		int destY;
		bool processing = false;
		bool ntrset = false;
		bool draw_effect = false;
		int idle_count = 0;
		Bullet(){}
		~Bullet() {}
		void setDest(int x, int y) {
			setPosition(TEMPLE_DEF_X+100, TEMPLE_DEF_Y+100);
			destX = x;
			destY = y;
		}
		bool updateBullet(){
			if (!processing) return false;
			if (idle_count < 150) {
				idle_count++;
				draw_effect = true;
				return true;
			}
			draw_effect = false;
			gotoDest(destX, destY);
			return true;
		}
		void gotoDest(int destx, int desty) {
			float sx = 0.0;
			float sy = 0.0;
			if (abs(destx - getPosition().x) > 0.0) {
				sx = (destx - getPosition().x) / TEMPLE_BULLET_MOVE_TIC;
			}
			if (abs(desty - getPosition().y) > 0.0) {
				sy = (desty - getPosition().y) / TEMPLE_BULLET_MOVE_TIC;
			}
			
			if (abs(destx - getPosition().x) < 3.0 && abs(desty - getPosition().y) < 3.0) {
				processing = false;
				ntrset = true;
			}
			setVelocity(sx, sy);
		}
		void resetIdle() {
			idle_count = 0;
		}
	};
	Bullet bullet;
	void drawEffect();
};

#endif

