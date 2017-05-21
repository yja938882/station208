#include "MentWindow.h"



MentWindow::MentWindow()
{
}


MentWindow::~MentWindow()
{
}

void MentWindow::load() {
	windowImage.load("images/window.png");
	font.loadFont("font/chfont.ttf", 24, true, true);
	font.setLineHeight(50);
	font.setLetterSpacing(1);
}

void MentWindow::show(int index) {
	str_cnt = 1;
	visible = true;
	show_index = index;
}

void MentWindow::close() {
	visible = false;
}
void MentWindow::update() {
	if (end_ment) {
		if (end_ment_cnt < chment.length()) {
			end_ment_cnt++;
			if (end_ment_cnt == chment.length() - 1) {
					game_end = true;
					
			}
		}
	}
	
	if (!visible)return;

	if (str_cnt < ments[show_index].length()) {
		str_cnt++;
	}
}
void MentWindow::draw() {
	if (end_ment) {
		windowImage.draw(MENT_END_X, MENT_END_Y, MENT_WINDOW_WIDTH, MENT_WINDOW_HEIGHT);
		ch_img.draw(MENT_END_X + 100, MENT_END_Y + 50, 250, 250);
		ofSetHexColor(0x00000);
		font.drawString(chment.substr(0, end_ment_cnt), MENT_END_X+460, MENT_END_Y+100);
		ofSetHexColor(0xffffff);
		
	}

	if (!visible)
		return;
	if (show_index < 3) {
		windowImage.draw(MENT_UP_DEF_X, MENT_UP_DEF_Y, MENT_WINDOW_WIDTH, MENT_WINDOW_HEIGHT);
		sign_img[show_index].draw(MENT_UP_SIGN_X, MENT_UP_SIGN_Y, MENT_SIGN_WIDTH, MENT_SIGN_WIDTH);
		ofSetHexColor(0x000000);
		font.drawString(ments[show_index].substr(0, str_cnt), MENT_UP_STR_DEF_X, MENT_UP_STR_DEF_Y);
		ofSetHexColor(0xffffff);
	}
	else {
		windowImage.draw(MENT_UP_DEF_X, MENT_UP_DEF_Y+MENT_DOWN_DIF_Y, MENT_WINDOW_WIDTH, MENT_WINDOW_HEIGHT);
		sign_img[show_index].draw(MENT_UP_SIGN_X, MENT_UP_SIGN_Y+MENT_DOWN_DIF_Y, MENT_SIGN_WIDTH, MENT_SIGN_WIDTH);
		ofSetHexColor(0x000000);
		font.drawString(ments[show_index].substr(0, str_cnt), MENT_UP_STR_DEF_X, MENT_UP_STR_DEF_Y+MENT_DOWN_DIF_Y);
		ofSetHexColor(0xffffff);
	}
}
void MentWindow::setSignImg(int index, ofImage img) {
	sign_img[index] = img;
}
void MentWindow::setChImg(ofImage img) {
	ch_img = img;
}
void MentWindow::showEndMent() {
	end_ment = true;
	//windowImage.draw(MENT_END_X, MENT_END_Y, MENT_WINDOW_WIDTH, MENT_SIGN_HEIGHT);
}
void MentWindow::closeEndMent() {
	end_ment = false;
}
void MentWindow::reset() {
	visible = false;
	end_ment = false;
	show_index = 0;
	str_cnt = 1;
	end_ment_cnt = 1;
	game_end = false;
}