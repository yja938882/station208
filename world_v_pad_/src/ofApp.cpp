#include "ofApp.h"
//글씨 있고(제목만) 표지판,,,  

//--------------------------------------------------------------
void ofApp::setup(){
	box2d.init();
	box2d.setGravity(0, 1);
	box2d.createBounds(0,0,1920,1080*2);
	
	load();
	setting();


	ofBackground(255, 255, 255);

	std::cout << "화면 위(1) | 아래(2) | 입력 >";
	std::cin >> screen;
	
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
	
	fbo.allocate(960, 540);
	fbo.begin();
	ofSetColor(0,0,0,70);
	backImage.draw(0, 0);
	//ofSetColor(255, 255, 255, 100);
	fbo.end();
	ofBackground(ofColor::white);
}


//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
	//ofSetFrameRate(30);
	vm.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (screen == 2)
		ofTranslate(0, -1080, 0);

	fbo.draw(480, 1080+ 270);

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
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (processing)return;
	processing = true;

	vm.playSubVideo();
	pads.push_back(shared_ptr<CustomParticle>(new CustomParticle));
	type = (num) % 3;
	pads.back().get()->setImage(padImages[(num++)%3], PAD_1_W, PAD_1_H, PAD_1_R);
	
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