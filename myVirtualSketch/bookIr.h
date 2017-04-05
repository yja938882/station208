#pragma once
#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"
class bookIr
{
public:
	void draw();
	void bookIr::draw(int x, int y);
	void setPos(float x, float y, float w, float h);
	void setImg();
	void setFont();
	void addString(string adds);
	void resetString();
	void setString(string set);

	void addString2(string adds);
	void setString2(string set);
	void setTitle(string t);

	void setHangle(string han);
	void setHangle2(string han);
	void bookIr::draw(int x, int y, int a);
	bookIr();
	~bookIr();

	ofImage img;
	float posX;
	float posY;
	float w;
	float h;
	string page1;
	string page2;
	string title="";
	string ttohan = "";
	string ttohan2 = "";
	ofxTrueTypeFontUC font;
	ofxTrueTypeFontUC font2;
	ofxTrueTypeFontUC font3;
	bool p1_han = false;
	bool p2_han = false;

	int start_index = 0;
	int end_index = 0;
};

