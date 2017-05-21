#pragma once

#include "ofMain.h"
#include "../Character.h"
#include "../Obs_pad.h"
#include "../Obs_stone.h"
#include "../Obs_wall.h"
#include "../Obs_Bridge.h"
#include "../Obs_rain.h"
#include "../Obs_corc.h"
#include "../Obs_umb.h"
#include "..//Obs_bal.h"
#include "../SoundManager.h"
#include "../Sign.h"
#include "../MentWindow.h"
#include "../Gage.h"
#include "ofxOsc.h"
#include "ofxNetwork.h"
#define PORT 4000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void load();
		void setting();

		/*box2d*/
		ofxBox2d box2d;

		/*Sound*/
		SoundManager sm;

		/*background*/
		ofFbo fbo;
		ofImage backImage;
		void drawToFbo();


		/*character*/
		ofImage ch_cryImages[4];
		ofImage ch_walkImages[3];
		Character ch;
		int ch_type = 0;

		/*Obstacles*/
		ofImage obs0_img;
		Obs_pad obs0;

		ofImage obs1_img;
		Obs_stone obs1;

		ofImage obs2_img;
		Obs_wall obs2;

		ofImage obs3_img;
		Obs_Bridge obs3;

		ofImage obs4_img[2];
		Obs_rain obs4;

		ofImage obs41_img;
		Obs_umb obs41;

		ofImage obs5_img;
		Obs_corc obs5;

		ofImage obs50_img;
		Obs_bal obs50;
		
		ofImage chf[2];

		/*MentWidnow*/
		MentWindow mentWindow;

		/*progress*/
		int progress = 0; //click num

		/*Sign*/
		Sign signs;
		ofImage signImages[6];

		ofImage schoolImg;

		void nextStage();

		/*Gage*/
		Gage gage;
		ofImage gageimg[2];

		ofxUDPManager udpConnection;
		void settingNetwork();
		void checkMsg();
		int proCount = 0;

		int end_ment_idle_tic = 0;
};
