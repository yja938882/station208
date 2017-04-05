#pragma once

#ifndef JU_APP_H
#define JU_APP_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSvg.h"
#include "../brailleset.h"
#include "../bTranslator.h"
//#include "../gage.h"
#include "../soundManager.h"
#include "../scatterEffecter.h"
#include "ofxTrueTypeFontUC.h"
#include "../bookIr.h"
#include "ofxOsc.h"
#include "../bookIr.h"


#define PORT 5001
#define NUM_MSG_sTRINGS 20


//#include "../wow.h"
class CustomParticle : public ofxBox2dRect {

public:
	ofFbo* fbo;
	ofImage img; //braille img
	string c;//character --mapping with img
	ofxTrueTypeFontUC *font;
	int posX, posY;
	string additional="";
	
	int w, h;
	
	bool tagged=false;


	bool yoyo = false;
	int yoyo_count=0;
	int basic_w, basic_h;
	int max_dw, max_dh;

	int yd;


	bool shake =true;
	bool shake_wish_to_stop = false;
	int shake_count = 0;
	float shake_deg = 0.0;
	float max_deg = 9.0;
	float sd = 2;

	bool slow_write = true;
	int test = 0;
	

	bool writing_p = false;

	bool moving_drawing_stop = false;
	bool fbo_drawing = false;

	bookIr *bir;
	int * pg;
	CustomParticle() {
	}
	void setupCustom(ofImage img, int x, int y , int w, int h, ofxTrueTypeFontUC* f) {
		CustomParticle::img = img;
		CustomParticle::posX = x;
		CustomParticle::posY = y;
		CustomParticle::w = w;
		CustomParticle::h = h;
		
		basic_w = w;
		basic_h = h;
		max_dw = 5;
		max_dh = 5;
		yd = 1;
		font = f;
	}
	void setBir(bookIr * bior, int *page) {
		bir = bior;
		pg = page;
	}

	void draw() {
		ofPushMatrix();
		posX = getPosition().x;
		posY = getPosition().y;
		float tposX = (float)w / 2.0 + posX;
		float tposY = (float)h / 2.0 + posY;
		ofTranslate(tposX,tposY, 0);
		ofRotate(shake_deg,0,0,1);
		img.draw(posX-tposX, posY-tposY, w, h);
		ofPopMatrix();
	
		ofSetColor(255,255,255);
		ofFill();
		ofRect(posX, posY + h+test, 100, 120-test);
	}
	void drawString() {
		ofSetColor(ofColor::black);
		font->drawString(c, posX + w / 4, posY + h + h / 2);
		ofSetHexColor(0xffffff);
	}

	void shakeProcess() {
		if (shake_count++ <= 10)return;
		shake_count = 0;

		if (shake_wish_to_stop){ //&& shake_deg == 0) {
			shake_deg = 0;
			shake = false;
			return;
		}
		if (shake_deg >= max_deg)
			sd = -sd;
		if (shake_deg <= -max_deg)
			sd = -sd;
		shake_deg += sd;
		

	}
	int update_() {
		int ret = 0;
		if (shake)shakeProcess();
		if (tagged) {
			shake_wish_to_stop = true;
			if (test <= 120) {
				if (writing_p) {
					test += 8;
				}
				if (test > 120) {
					
					writing_p = false;
					moving_drawing_stop = true;
					if(additional.length()>=1)
						if (additional.at(0) == ' ')ret = 1;

				}
			}
		}
		return ret;
	}
	float getBottomY() {
		return posY + basic_h;
	}
	float getX() {
		return posX;
	}
};


class DrawingTool : public ofxBox2dRect {

public:
	ofImage img; //braille img
	string c;//character --mapping with img
	ofTrueTypeFont *font;
	int posX, posY;

	int w, h;


	int basic_w, basic_h;
	int max_dw, max_dh;
	int yd;


	bool shake = false;
	bool shake_wish_to_stop = false;
	int shake_count = 0;
	float shake_deg = -210.0;
	float max_deg = 350.0;
	float sd = 2;

	bool writing = false;
	
	int move_count = 0;
	int w_len = 0;
	int w_height = 0;
	float w_d=0.0;
	float w_x = 0.0;

	bool stop_spin = false;
	int stop_spin_count = 0;
	float accel = 0.2;
	float accum = 0.0;

	DrawingTool() {
	}
	void setupDrawingTool(int x, int y) {
		DrawingTool::img.load("images/drawing_tool.png");
		DrawingTool::posX = x;
		DrawingTool::posY = y;
		DrawingTool::w = img.getWidth();
		DrawingTool::h = img.getHeight();
		basic_w = w;
		basic_h = h;
		max_dw = 5;
		max_dh = 5;
		yd = 1;
	}

	void draw() {
		ofPushMatrix();
		float tposX = (float)w / 2.0 + getPosition().x;
		float tposY = (float)h / 2.0 + getPosition().y;
		ofTranslate(tposX, tposY, 0);
		ofRotate(shake_deg+w_d, 0, 0, 1);
		img.draw(getPosition().x - tposX+w_x, getPosition().y - tposY, w, h);

		ofPopMatrix();
	}
	void update() {
		if (stop_spin)stopSpinProcess();
		if (writing)writingProcess();
	}
	void startWriting(int posX, int posY, int word_len, int height) {
		setPosition(posX, posY);
		shake_deg = -210.0;
		w_len = word_len;
		w_height = height;
		writing = true;
		
	}
	void writingProcess() {
		if (move_count <= 30) {
			if (move_count == 0) {
				shake_deg = -210.0;
			}
			move_count++;
			setPosition(getPosition().x, getPosition().y + 2);
			if (move_count <= 15) {
				w_d += 0.9;
				w_x += 3;
				
			}
			else {
				w_d-=0.9;
				w_x -= 3;
			}
			//shake_deg += 1;
		}
		else {
			move_count = 0;
			w_d = 0.0;
			w_x = 0;
			writing = false;
		}
	}
	void stopSpinProcess() {
		if (stop_spin_count <= 200) {
			stop_spin_count++;
			w_d += accel;
			if(stop_spin_count <=20)
				accel += 0.5;
				
		}else {
			w_d = 0.0;
			stop_spin = false;
			stop_spin_count = 0;
			accel = 0.2;
		}
		if (writing) {
			w_d=0.0;
			stop_spin = false;
			stop_spin_count = 0;
			accel = 0.2;
		}
	}

	float getBottomY() {
		return posY + basic_h;
	}
	float getX() {
		return posX;
	}
};

class gage
{
public:
	int PstartX;
	int PstartY;
	int Pwidth;
	int Pheight;
	int num=0;
	ofxTrueTypeFontUC font;

	int MAX = 960;
	ofImage gageImage;
	gage() {

	}
	~gage() {

	}
	
	void setGage() {
		gageImage.load("images/ui/gage.png");
		PstartX = 54;
		PstartY = 26;
		Pwidth = 1;
		Pheight = 47;
		font.loadFont("font/gagefont.ttf", 20, true, true);
	}
	void draw() {
		gageImage.draw(0, 0, 1080, 99);
		ofSetColor(255, 0, 102);
		ofFill();
		ofRect(PstartX, PstartY, Pwidth, Pheight);
		ofSetColor(ofColor::black);
		font.drawString("지금까지 "+to_string(num)+"분이 참여하셨습니다.",290,120);
		ofSetColor(255);
	}
	void upGage() {
		float up = (float)MAX *((float)1.0 / 400.0);
		Pwidth += (int)up;
		num++;
	}
};

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
		
		void setLetters();
		void resetLetters();
		void writingWord();
		void updateWriting();

		void setStars();
		void scatterStars();
		void drawForComplete();
		void drawToFbo();
		void scatterStars(int x, int y);

		ofxBox2d                                box2d;			  //	the box2d world

		vector		<shared_ptr<CustomParticle> >		letters;			  //	defalut box2d rects
		
		brailleset braille_set;
		bTranslator trans;
		int BRAILLE_WIDTH;
		int BRAILLE_HEIGHT;
		int SPACE_WIDTH;
		int INTERVAL_WIDTH;
		int INTERVAL_HEIGHT;
		int FONT_SIZE;
		int LINE_LETTER_NUM;
		ofxTrueTypeFontUC bookfont_large;

		DrawingTool pen;

		bool test=false;

	
		gage progGage;

		soundManager sManager;


		
		int* letter_of_word_nums;
		int word_num;
		int w_index = 0;
		int c_index = 0;
		int c_endIndex = -1;
		string current_string="";
		string current_word="";
		int cs_index=0;
		
	

		bool word_writing = false;
		int ws_index;
		int we_index;


		int tick_count = 0;

		int current_book = 0;
		int current_page = 0;

		ofImage manualImg;
		string manualString = "이번 모금은 교내 장애인 인식 개선 프로젝트 추진을 위해 사용될 계획입니다.\n"
						      "여러분의 참여로 모인 소중한 기금은 4월 27일 제 37회 장애인 날 기념 행사에서\n"
						      "장애학생인권위원회에 전액 전달 될 예정입니다.";
		string manualString2 = "   기부를 통해 점자 그림책을 완성해주세요!";
		
		
		ofxTrueTypeFontUC manfont;
		ofxTrueTypeFontUC manfont2;
		//scatterEffecter star;
		//ofImage starImg;

		vector		<shared_ptr<scatterEffecter> >		stars;
		ofImage redstarImg;
		ofImage yellowstarImg;
		ofImage bluestarImg;
		bool stars_show = true;

		ofFbo fbo;


		bookIr book_ir;

		ofVec2f v;


		

		//void gotMessage(ofMessage msg);
		void osc208();

		ofxOscReceiver receiver;

		float bang;
		int mbangsw;
		int abb;//연속뱅 방지
		int abbco;//연속뱅 방지 카운터

		int t;

		ofImage bgImg;

		ofColor backcolor ;
		int tempin=0;

		bool completeprocess = false;
		int completeCounter = -1;
		int wating_count=0;
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
#endif