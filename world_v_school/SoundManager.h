#pragma once
#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H
#include "ofSoundPlayer.h"
class SoundManager
{
public:
	ofSoundPlayer babam;
	SoundManager();
	~SoundManager();
	void load();
	void playBabam();
};


#endif

