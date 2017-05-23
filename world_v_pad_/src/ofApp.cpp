#include "ofApp.h"
//글씨 있고(제목만) 표지판,,,  

//--------------------------------------------------------------
void ofApp::setup(){
	receiver.setup(PORT);
	bang = 0;


	box2d.init();
	box2d.setGravity(0, 5);
	box2d.createBounds(0,0,1920,1080*2);
	
	load();
	setting();


	ofBackground(255, 255, 255);


	vm.playMainVideo();
}
void ofApp::load() {
	std::cout << "#> load pad images ... ";
	for (int i = 0; i < 3; i++) {
		string path = "images/pad" + to_string(i) + ".png";
		padImages[i].load(path);
	}
	std::cout << "complete!!\n";


	std::cout << "#> load videos ... ";
	vm.load();
	std::cout << "complete!!\n";

	std::cout << "#> load background images ... ";
	backImage.load("images/back.png");

	
	

}
void ofApp::setting() {
	
	fbo.allocate(960, 960);
	fbo.begin();
	//ofSetColor(0,0,0,70);
	ofSetHexColor(0xffffff);
	backImage.draw(0, 0,960,960);
	//ofSetColor(255, 255, 255, 100);
	fbo.end();
	ofBackground(ofColor::white);
}


//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(140);
	osc208();
	if (bang != 0 && abb == 0) {
		abb = 1;

		//osc신호가 왔을때 이곳에 입력된 명령이 실행됨.
		if (processing)return;
		processing = true;

		vm.playSubVideo();
		pads.push_back(shared_ptr<CustomParticle>(new CustomParticle));
		type = (num) % 3;
		pads.back().get()->setImage(padImages[(num++) % 3], PAD_1_W, PAD_1_H, PAD_1_R);



	}
	
	

	box2d.update();

	vm.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofTranslate(0, -1080, 0);

	fbo.draw((1920-960)/2, 1080+ (1080-960)/2);

	if (processing) {
		if (drawProcessing()) {
			pads.back().get()->setPhysics(1, 0.2, 0.2);
			pads.back().get()->setup(box2d.getWorld(), 1980 / 2, 1080, PAD_1_R - PAD_1_M);
			ofVec2f f;
			f.set(ofRandom(-1, 1), 0);
			pads.back().get()->addForce(f, 50);
			idle_count = PAD_1_IDLE_MAX;
			type = -1;
			idle_deg = 0.0;
		}
	}

	vm.draw();
	for (int i = 0; i < pads.size(); i++) {
		if (processing && i==pads.size()-1) {
			break;
		}
		pads[i].get()->drawImage();
	}
	if (pads.size() >= 130) {
		for (int i = 0; i < 30; i++) {
			pads.pop_back();
		}
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//osc신호가 왔을때 이곳에 입력된 명령이 실행됨.
	if (processing)return;
	processing = true;

	vm.playSubVideo();
	pads.push_back(shared_ptr<CustomParticle>(new CustomParticle));
	type = (num) % 3;
	pads.back().get()->setImage(padImages[(num++) % 3], PAD_1_W, PAD_1_H, PAD_1_R);
	std::cout << "num : " + to_string(pads.size()) + "\n";
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

bool ofApp::drawProcessing() {
	if (!processing)return false;
	if (type == -1)return false;
	idle_count--;
	idle_deg += 1.0;
	float cx = PAD_1_DEF_X;
	float cy = PAD_1_DEF_Y;
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
	padImages[type].draw(PAD_1_DEF_X-PAD_1_RAD*2, PAD_1_DEF_Y - PAD_1_RAD * 2, PAD_1_W, PAD_1_H);
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

