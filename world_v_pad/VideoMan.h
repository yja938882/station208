#pragma once
#ifndef VIDEO_MAN_H
#define VIDEO_MAN_H
#include "ofVideoPlayer.h"
class VideoMan
{
public:
	ofVideoPlayer mainPlayer;
	ofVideoPlayer sub0Player;
	ofVideoPlayer sub1Player;
	int sub_index = 0; // play and index up;

	VideoMan();
	~VideoMan();
	bool play_main = true;

	void load();
	void playMainVideo();
	void playSubVideo();
	void update();
	void draw();
private:
	void drawMainVideo();
	void drawSubVideo();
};
#endif
