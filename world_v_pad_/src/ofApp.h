#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxBox2d.h"
#include "../CustomParticle.h"
#include "../VideoMan.h"
#define PORT 5001

class ofApp : public ofBaseApp{

	public:
		bool sub = false;
		bool scatt = false;

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
	

		ofxBox2d box2d;

		ofImage padImages[3];
		ofImage backImage;

		ofFbo fbo;

		vector <shared_ptr<CustomParticle>> pads;

		VideoMan vm;
		
		int screen;
		int num = 0;
		bool processing = false;

		int idle_count = PAD_1_IDLE_MAX;
		int type = -1;
		float idle_deg = 0.0;
		bool drawProcessing();




		void osc208();
		ofxOscReceiver receiver;

		float bang;
		int mbangsw;
		int abb;//연속뱅 방지
		int abbco;//연속뱅 방지 카운터
};
