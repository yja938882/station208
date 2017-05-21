#include "SoundManager.h"



SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::load() {
	babam.load("sound/babam.wav");
}
void SoundManager::playBabam() {
	babam.play();
}