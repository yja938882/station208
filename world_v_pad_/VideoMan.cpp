#include "VideoMan.h"



VideoMan::VideoMan()
{
}


VideoMan::~VideoMan()
{
}


void VideoMan::load() {
	std::cout << "> load video/main.mp4 ...";
	mainPlayer.loadMovie("video/main.mp4");
	std::cout << "complete!\n";

	std::cout << "> load video/sub0.mp4 ...";
	sub0Player.loadMovie("video/sub0.mp4");
	std::cout << "complete!\n";

	//std::cout << "> load video/sub1.mp4 ...";
	//sub1Player.loadMovie("video/sub1.mp4");

}

void VideoMan::playMainVideo() {
	mainPlayer.play();
}
void VideoMan::playSubVideo() {
	mainPlayer.firstFrame();
	mainPlayer.stop();
	play_main = false;

	//if (sub_index == 0)
		sub0Player.play();
	//else if (sub_index == 1)
		//sub1Player.play();

}

void VideoMan::update() {
	if (play_main) {
		mainPlayer.update();
	}
	else {
	//	if (sub_index == 0) {
			sub0Player.update();
			if (sub0Player.getPosition() >= 0.99f) {
				sub0Player.firstFrame();
				sub0Player.stop();
			//	sub_index = 1;


				play_main = true;
				playMainVideo();
			}
		}
		//else if (sub_index == 1) {
		//	sub1Player.update();
		//	if (sub1Player.getPosition() >= 0.99f) {
			////	sub1Player.firstFrame();
			//	sub1Player.stop();
			//	sub_index = 0;


			//	play_main = true;
			//	playMainVideo();
			//}
	//	}
	//}
}


void VideoMan::draw() {
	if (play_main) {
		drawMainVideo();
	}
	else {
		drawSubVideo();
	}
}
void VideoMan::drawMainVideo() {
	mainPlayer.draw(0, 0, 1920, 1080);
}
void VideoMan::drawSubVideo() {
//	if (sub_index == 0) {
		sub0Player.draw(0, 0, 1920, 1080);
//	}
	//else if (sub_index==1) {
	//	sub1Player.draw(0, 0, 1920, 1080);
	//}
}