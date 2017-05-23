#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "../CustomParticle.h"
#include "ofxOsc.h"
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1920*2
#define PAD_DEF_X 1080/2
#define PAD_DEF_Y 1920
#define COUNT_MAX 4800
#define COUNT_MD COUNT_MAX/6
#define TAN_10 0.6483
#define TL 1500
#define DEG(x) (x)*(3.1416/180.0)


#define PIC_W 1080 - 108*2
#define PIC_H 300
//(1920 - 198*2)/6
#define PIC_DEF_X 108
#define PIC_DEF_Y 40
#define PIC_INC_Y 198

class ofApp : public ofBaseApp{

	public:
		bool attraction = false;
		float attX = 0.0;
		float attY = 0.0;
		int attWay = 0;
		int count=0;

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
		void updateAttractionPoint();


		bool ofApp::drawProcessing();
		ofxBox2d box2d;

		ofImage padImages[3];
		ofImage backImage;
		vector <shared_ptr<CustomParticle>> pads;

		int num = 0;

		bool processing = false;

		int idle_count = PAD_IDLE_MAX;
		int type = -1;
		float idle_deg = 0.0;

		ofFbo fbo;
		ofImage imgs[6];

		int img_index = 0;

		ofSoundPlayer sp;

		void osc208();
		ofxOscReceiver receiver;

		float bang;
		int mbangsw;
		int abb;//연속뱅 방지
		int abbco;//연속뱅 방지 카운터

};

