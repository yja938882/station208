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
		//������ǰ ����
		"���� ���ߵ��󱹿��� ������� ���ϱ� ����� ��ǰ�Դϴ�.\n"
		"���� �ִ� ���� �ʰ��� ���� ����ϱ⵵ ������ �׻� �����\n"
		"�Ҿȿ� �ô޸��ϴ�. ������ ���� ������ �б��� ���� ���ϴ�\n"
		"���Ƶ鵵 �ִµ� �̷� ��� �о��� �������� �˴ϴ�."
		,
		//����뵿
		"�θ���� ���踦 ���� ���Ͻø� ������ ���ھ��̰� ��������\n"
		"���ý��ϴ�. �������� �����ų� ���� �������� ��ȣ�ϴ� �͵�\n"
		"���������� �Ƶ麸�ٴ� ���� �þƾ� �� �Ϸ� ����� ��찡 �����ϴ�."
		,
		//��ȥ�� �Խ�
		"���ߵ��󱹿� ������ ��ȥ�� ���ھ��̵��� �о��� �ߴ��ϰ� \n"
		"�ڱ� ������ ��ȸ�� �Ұ� �ϴ� ������ �˴ϴ�.\n"
		"������, ������ ������ 18�� ������ ��ȥ�ϴ� ���Ƶ���\n"
		"�ʹ� � ���̿� �̷��� �ӽŰ� ������� �ǰ��� ��ȭ�Ǳ⵵ �մϴ�."
		,
		//�б�����
		"�б��� ���� ���� �ʾ� �б������� �Ÿ��� �ʹ� �� ������ȸ����,\n"
		"�θ���� ������ �� ���� �ɾ� �����ϴ� ���� ������ �ʽ��ϴ�.\n"
		"���� ������ ���� �Ӵ��� ���� �����ִ� �ð���ŭ �������� \n"
		"���� ��Ʊ� �����Դϴ�."
		,
		//�����ü�����
		"��κ��� �б����� ���л� ���� ȭ����� ����, �ִ���\n"
		"���������� �İ� ó���� �� �ִ� ������ �����մϴ�.\n"
		"���� �����Ⱓ�� Ư�� ū ������� ������ ���л��鿡�� \n"
		"��� �ްų� ���� ������ ��� �������� ǥ���� �Ǳ⵵ �մϴ�. "
		,
		//���
		"������ ������ ���ھ��̸� �б��� ������ ���� �켱������\n"
		"�ǰ� �մϴ�. Ư�� ������, �������� ���� ���� ������ ������\n"
		"������ ��������� ���� ������ȸ�� ���, ���Ƶ��� ������\n"
		"�ʼ������� �ʴٰ� �������⵵ �մϴ�."
	};
	const string chment = "����!!\n���п� �б��� �� �����߾�!!";
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