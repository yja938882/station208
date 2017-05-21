#pragma once
#ifndef MENT_WIDNOW_H
#define MENT_WINDOW_H
#include "ofImage.h"
#include "ofxTrueTypeFontUC.h"
#include "ofMain.h"
#define MENT_WINDOW_WIDTH 1500
#define MENT_WINDOW_HEIGHT 350

#define MENT_UP_DEF_X (1920-MENT_WINDOW_WIDTH)/2
#define MENT_UP_DEF_Y 70

#define MENT_DOWN_DIF_Y 600

#define MENT_UP_STR_DEF_X MENT_UP_DEF_X+460
#define MENT_UP_STR_DEF_Y MENT_UP_DEF_Y+100

#define MENT_SIGN_WIDTH 250
#define MENT_SIGN_HEIGHT 250

#define MENT_UP_SIGN_X MENT_UP_DEF_X+100
#define MENT_UP_SIGN_Y MENT_UP_DEF_Y+30

#define MENT_END_X 200
#define MENT_END_Y 350

#define MENT_END_IDLE 200

class MentWindow
{
private :
	bool visible = false;
	bool end_ment = false;
	int show_index = 0;
	int str_cnt = 1;
	int end_ment_cnt = 1;


	ofImage windowImage;
	ofImage sign_img[6];
	ofImage ch_img;
	ofxTrueTypeFontUC font;
	const string ments[7] = {
		//위생용품 부족
		"많은 개발도상국에서 생리대는 구하기 어려운 물품입니다.\n"
		"집에 있는 낡은 옷가지 등을 사용하기도 하지만 항상 불편과\n"
		"불안에 시달립니다. 생리가 끝날 때까지 학교에 가지 못하는\n"
		"여아들도 있는데 이런 경우 학업에 뒤쳐지게 됩니다."
		,
		//가사노동
		"부모님이 생계를 위해 일하시면 집안의 여자아이가 가사일을\n"
		"도맡습니다. 동생들을 돌보거나 아픈 가족들을 간호하는 것도\n"
		"마찬가지로 아들보다는 딸이 맡아야 할 일로 여기는 경우가 많습니다."
		,
		//조혼과 입신
		"개발도상국에 만연한 조혼은 여자아이들이 학업을 중단하고 \n"
		"자기 개발의 기회를 잃게 하는 원인이 됩니다.\n"
		"경제적, 관습적 이유로 18세 이전에 결혼하는 여아들은\n"
		"너무 어린 나이에 이뤄진 임신과 출산으로 건강이 악화되기도 합니다."
		,
		//학교부족
		"학교의 수가 많지 않아 학교까지의 거리가 너무 먼 지역사회에서,\n"
		"부모들은 딸들이 먼 길을 걸어 통학하는 것을 원하지 않습니다.\n"
		"안전 문제도 있을 뿐더러 집을 떠나있는 시간만큼 가사일을 \n"
		"돕기 어렵기 때문입니다."
		,
		//위생시설부족
		"대부분의 학교에는 여학생 전용 화장실이 없고, 있더라도\n"
		"위생적으로 씻고 처리할 수 있는 공간이 부재합니다.\n"
		"따라서 생리기간에 특히 큰 어려움을 겪으며 남학생들에게 \n"
		"놀림을 받거나 더욱 위험한 경우 성범죄의 표적이 되기도 합니다. "
		,
		//빈곤
		"가정이 어려우면 남자아이를 학교에 보내는 것이 우선순위가\n"
		"되곤 합니다. 특히 관습적, 종교적인 이유 등의 이유로 여성의\n"
		"지위가 상대적으로 낮은 지역사회의 경우, 여아들의 교육은\n"
		"필수적이지 않다고 여겨지기도 합니다."
	};
	const string chment = "고마워!!\n덕분에 학교에 잘 도착했어!!";
public:
	bool game_end = false;
	MentWindow();
	~MentWindow();
	void setSignImg(int index, ofImage img);
	void load();
	void show(int index);
	void close();
	void update();
	void draw();
	void setChImg(ofImage img);
	void showEndMent();
	void closeEndMent();
	void reset();
};

#endif