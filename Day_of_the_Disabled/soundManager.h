#pragma once
#include "ofMain.h"
class soundManager
{
	
public:
	const static int TAG1_SOUND = 0;
	const static int BACK_SOUND = 1;
	const static int BABAM_SOUND = 2;
	soundManager();
	~soundManager();
	ofSoundPlayer babam;
	ofSoundPlayer tag1;
	ofSoundPlayer back;
	void loadSounds();
	void playSound(int type);
};

