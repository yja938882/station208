#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sp.load("babam.wav");
	for (int i = 0; i < 3; i++) {
		string path = "images/pad" + to_string(i) + ".png";
		padImages[i].load(path);
	}
	for (int i = 0; i < 6; i++) {
		string path = "images/" + to_string(i) + ".png";
		imgs[i].load(path);
	}

	backImage.load("images/back.png");

	fbo.allocate(960, 960);
	fbo.begin();
	//ofSetColor(255, 255, 255,70);
	ofSetHexColor(0xffffff);
	backImage.draw(0, 0);
	fbo.end();
	ofBackground(ofColor::white);

	box2d.init();
	box2d.setGravity(0, 5);
	box2d.createBounds(0, 0, 1080, 1920 * 2);
	ofSetVerticalSync(false);

	ofBackground(ofColor::white);
	for (int i = 0; i < 5; i++) {
		pads.push_back(shared_ptr<CustomParticle>(new CustomParticle));
		pads.back().get()->setImage(padImages[i % 3], PAD_W, PAD_H, PAD_R);
		pads.back().get()->setPhysics(1, 0.2, 0.2);
		pads.back().get()->setup(box2d.getWorld(), (SCREEN_WIDTH/7)*(i+1), PAD_DEF_Y, PAD_R);
		pads.back().get()->setRotation(ofRandom(0, 360.0));

	}
}

//--------------------------------------------------------------
void ofApp::update(){
	osc208();
	if (bang != 0 && abb == 0) {
		abb = 1;

		if (processing)return;
		processing = true;
		sp.play();
		type = (num) % 3;
		pads.push_back(shared_ptr<CustomParticle>(new CustomParticle));
		pads.back().get()->setImage(padImages[(num++) % 3], PAD_W, PAD_H, PAD_R);



	}



	ofSetFrameRate(140);
	box2d.update();
	updateAttractionPoint();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofRotateZ(-90);
	ofTranslate(-1080, 0, 0);

	//ofTranslate(0, -1920, 0);

	fbo.draw((SCREEN_WIDTH-960)/2, SCREEN_HEIGHT / 2 + ((SCREEN_HEIGHT/2)-960)/2);

	if (processing) {
		if (drawProcessing()) {
		
			pads.back().get()->setPhysics(1, 0.2, 0.2);
			pads.back().get()->setup(box2d.getWorld(), SCREEN_WIDTH/2, SCREEN_HEIGHT/2, PAD_R);
			ofVec2f f;
			f.set(ofRandom(-1, 1), 0);
			pads.back().get()->addForce(f, 50);
			idle_count = PAD_IDLE_MAX;
			type = -1;
			idle_deg = 0.0;
		}
	}

	for (int i = 0; i < 6; i++) {
	
		if (img_index == i) {
			continue;
		
		}
		imgs[i].draw(PIC_DEF_X, 80 + PIC_H*i, PIC_W, PIC_H);
	
	}
	if (count % 4800 <= 80) {
		imgs[img_index].draw(PIC_DEF_X - img_index * 2, 80 + PIC_H*img_index - img_index, PIC_W + img_index * 2, PIC_H + img_index);
	}
	else {
		imgs[img_index].draw(PIC_DEF_X - 80, 80 + PIC_H*img_index - 40, PIC_W + 160, PIC_H + 80);
	}



	for (int i = 0; i < pads.size(); i++) {
		if (processing && i == pads.size() - 1) {
			break;
		}

		pads[i].get()->drawImage();
		//pads[i].get()->draw();
		
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mbangsw = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mbangsw = 0;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::updateAttractionPoint() {
	
	
	count++;

	if (count > COUNT_MAX)
		count = 0;

	if (count >= 0 && count <= COUNT_MD) {
		img_index = 0;
	}
	else if (count > COUNT_MD && count <= COUNT_MD * 2) {
		img_index = 1;
	}
	else if (count > COUNT_MD * 2 && count <= COUNT_MD * 3) {
		img_index = 2;
	}
	else if (count > COUNT_MD * 3 && count <= COUNT_MD * 4) {
		img_index = 3;
	}
	else if (count > COUNT_MD * 4 && count <= COUNT_MD * 5) {
		img_index = 4;
	}
	else if (count > COUNT_MD * 5 && count <= COUNT_MD * 6) {
		img_index = 5;
	}

}
bool ofApp::drawProcessing() {
	if (!processing)return false;
	if (type == -1)return false;
	idle_count--;
	idle_deg += 1.0;
	float cx = PAD_DEF_X;
	float cy = PAD_DEF_Y;
	if (idle_count <= 0) {
		processing = false;
		type = -1;

		return true;
	}
	ofPushMatrix();
	ofTranslate(cx, cy);
	ofRotate(idle_deg);

	ofSetColor(255, 255, 224, 90);
	ofFill();
	for (int i = 0; i < 8; i++) {
		ofTriangle(0, 0,
			TL*cos(DEG(45 * i + 10)), -TL*sin(DEG(45 * i + 10)),
			TL*cos(DEG(45 * i - 10)), -TL*sin(DEG(45 * i - 10))
		);
	}
	ofSetHexColor(0xffffff);
	ofPopMatrix();
	padImages[type].draw(PAD_DEF_X - PAD_R * 2, PAD_DEF_Y - PAD_R * 2, PAD_W, PAD_H);
	return false;

}

void ofApp::osc208() {

	bang = 0;
	while (receiver.hasWaitingMessages()) {

		ofxOscMessage m;
		receiver.getNextMessage(m);

		for (int i = 0; i < m.getNumArgs(); i++) {
			if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
				bang = m.getArgAsFloat(0);
			}
		}
	}

	if (mbangsw == 1) {
		bang = 1;
	}

	if (abb == 1) {
		abbco += 1;
		if (abbco > 610) {
			abb = 0; abbco = 0;
		}
	}
}
