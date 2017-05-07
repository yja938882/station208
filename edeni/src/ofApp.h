#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "../Sun.h"
#include "../Angel.h"
#include "../Gage.h"
#include "../Cloud.h"
#include "../House.h"
#include "../BTHouse.h"
#include "../Temple.h"
#include "../TimeMan.h"
#include "ofxOsc.h"
#define PORT 5001
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
		//-------------------------------------------
		
		void loadImages();
		void loadSounds();

		void proc();



		//-------------------------------------------
		/* box2d */
		ofxBox2d box2d;

		/*Fbo*/
		ofFbo fbo;
		void drawToFbo();

		/*Background*/
		ofImage top_back_day;
		ofImage bottom_back_day;

		ofImage top_back_night;
		ofImage bottom_back_night;

		/*Cloud*/
		ofImage cloudImg[CLOUD_NUM];
		Cloud cloud[CLOUD_NUM];
		void setupClouds();

		/*Gage*/
		Gage gage;

		/*Sun*/
		Sun sun;
		
		ofImage sunImage[2];
		ofImage moonImage[2];
		ofImage sunmaneImage;
		void setupSun();

		/*Angel*/
		Angel angel_0;
		Angel angel_1;
		ofImage leftWingImg, rightWingImg;
		ofImage angel_0_Image;
		ofImage angel_1_Image;
		void setupAngel();

		/*House*/
		ofImage houseImages[HOUSE_TYPE_NUM * 6];
		House curHouse;
		int curHouseIndex = 0;//0 to 8
		int curHouseBlockIndex = -1; //0 to 4
		void setupHouse();
		void setupNextHouse();

		ofImage bottomHouseImages[HOUSE_TYPE_NUM];
		BTHouse bthouse;

		ofImage templeHouseImgs[9];
		ofImage templeImage;
		Temple temple;
		void setupTemple();
		int bottom_house_index = 0;
		void drawBottomHouseToFbo();

		/*input lock*/
		bool inputlock = false;


		/*position data*/
		int bbx_for_an0[5 * HOUSE_TYPE_NUM] =
		{
			333 , 519 , 697 , 875 , 855 //house0
			, 663 , 397 , 836 , 841 , 953//house1
			, 426 , 604 , 776 , 837 , 776 //house2
			, 618 , 624 , 373 , 865 , 890 //house3
			, 744 , 619 , 498 , 804 , 813 //house4
			, 611 , 480 , 739 , 774 , 774//house5
			, 624 , 384 , 616 , 854 , 848 //house6
			,619 , 383 , 821 , 335 , 913 //house7
			, 625 , 381 , 869 , 907 , 919 //house8

		};
		int bbx_for_an1[5 * HOUSE_TYPE_NUM] =
		{
			197 , 380 , 562 , 743 , 227 //house0
			, 383 , 241 , 683 , 695 , 115 //house1
			, 295 , 476 , 651 , 765 , 305 //house2
			, 458 , 455 , 213 , 710 , 192 //house3
			, 582 , 459 , 322 , 675 , 273 //house4
			, 468 , 344 , 596 , 676 , 288//house5
			, 460 , 230 , 461 , 697 , 233 //house6
			, 455 , 241 , 683 , 248 , 180 //house7
			, 454 , 210 , 697 , 825 , 153 //house8
		};

		int bby_for_ang[5 * HOUSE_TYPE_NUM] =
		{
			402 , 402 , 402 , 402 , 223 //house0
			, 717 , 567 , 552 , 127 , 300 //house1
			, 608 , 608 , 608 , 264 , 307 //house2
			, 611 , 352 , 525 , 525 , 252 //house3
			, 690 , 393 , 705 , 242 , 521 //house4
			, 415 , 720 , 704 , 286 , 486 //house5
			, 742 , 540 , 336 , 549 , 300 //house6
			,  543 , 440 , 437 , 140 , 283 //house7
			, 573 , 522 , 522 , 48	, 261 //house48
		};
		int bottom_y_for_house[27] = {
			553,553,553,553, //4
			690, 690,690, //3
			770, 770,770,770, //4
			903, 903,903,903,
			1061,
			1009,1009,
			1397,1397,
			1555,1555,1555,
			1711, 1711, 1711,
			1801
		};

		int bottom_x_for_house[27] = {
			415,600,785,970,
			-40,115,280,
			400,585,770,955,
			50,235,420,605,
			20,
			770,955,
			600,785,
			0,185,370,
			500,685, 870,
			0	};
		int mode = 0;
		int screen = 0;

		ofImage manImg;
		ofxTrueTypeFontUC manfont;
		ofxTrueTypeFontUC manfont2;
		string manSmall = "이든아이빌은 왕십리에 위치한 지역 아동 복지센터로,\n"
			"1950년 개원하여 지금까지 성동구 지역 아이들의 보호와 양육, 교육을\n 담당하고 있습니다.";
		string manBig = "이번 모금은 아이들에게 더 나은 환경을 제공하기위해 사용됩니다.";

		TimeMan tm;
		bool isDay; //true - day , false  - night
		void setByDay();
		void save(int num);
		int load();
		int loaded_num=0;

		ofSoundPlayer next_house_sound;
		ofSoundPlayer block_sound;

	
		//-----------------------------
		void osc208();

		ofxOscReceiver receiver;

		float bang;
		int mbangsw;
		int abb;//연속뱅 방지
		int abbco;//연속뱅 방지 카운터

		int t;

		ofImage bgImg;

		ofColor backcolor;
		int tempin = 0;

		bool completeprocess = false;
		int completeCounter = -1;
		int wating_count = 0;
		int bookmv = 0;

		int r = 20;

		ofImage addbook;

		int wtobookindex = 0;

		int rad = 300;
		int dr = 12;
		int comdp = 0;
		int alp = 255;

		int real_tick = 0;
		int frame_r = 0;
};
