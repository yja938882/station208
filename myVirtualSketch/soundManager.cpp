#include "soundManager.h"



soundManager::soundManager()
{
}


soundManager::~soundManager()
{
}

void soundManager::loadSounds() {
	tag1.load("sounds/tag1.mp3");
	back.load("sounds/back.mp3");
	babam.load("sounds/babam.wav");
	
}
void soundManager::playSound(int type) {
	switch (type) {
	case TAG1_SOUND:
		tag1.play();
		break;
	case BACK_SOUND:
		back.play();
		break;
	case BABAM_SOUND:
		babam.play();
		break;
	}
}