#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(60);
	box2d.registerGrabbing();

	load();
	setting();
	drawToFbo();

	settingNetwork();

	
}
void ofApp::settingNetwork() {
	std:cout<<"#> Setting Network ...\n";
	udpConnection.Create();
	udpConnection.Bind(PORT);
	udpConnection.SetNonBlocking(true);
}
void ofApp::load() {
	/*Load Sounds*/
	std::cout << "#> Load Sounds ...\n";
	sm.load();

	/*Load Background Image*/
	std::cout << "#> Load Background Image ...\n";
	backImage.load("images/back/background.png");

	/*Load Character0 Image*/
	std::cout << "#> Load Character 0 Images ...\n";
	for (int i = 0; i < 4; i++) {
		string path = "images/character/character0/cry0"+to_string(i)+".png";
		ch_cryImages[i].load(path);
	}
	for (int i = 0; i < 3; i++) {
		string path = "images/character/character0/walk0" + to_string(i) + ".png";
		ch_walkImages[i].load(path);
	}

	/*Load CharacterFont */	
	std::cout << "#> Load Character Font ...\n";
	ch.bub.loadFont();

	/*Load Character Bub Image*/
	std::cout << "#> Load Character Bub image ...\n";
	ch.bub.img.load("images/character/bub.png");

	/*Load Sign Images*/
	std::cout << "#> Load Sign Image ...\n";
	//signImages[0].load("images/sign00.png");
//	signImages[1].load("images/obstacles/sign_yes.png");
	for (int i = 0; i < 6; i++) {
		string path = "images/sign/sign" + to_string(i) + ".png";
		signImages[i].load(path);
	}

	/*Load Obstacle 0 Image*/
	std::cout << "#> Load Obstacle 0 Image ...\n";
	obs0_img.load("images/obstacles/obs0.png");

	/*Load Obstacle 1 Image*/
	std::cout << "#> Load Obstacle 1 Image ...\n";
	obs1_img.load("images/obstacles/obs1.png");

	/*Load Obstacle 2 Image*/
	std::cout << "#> Load Obstacle 2 Image ...\n";
	obs2_img.load("images/obstacles/obs2.png");

	/*Load Obstacle 3 Image*/
	std::cout << "#> Load Obstacle 3 Image ...\n";
	obs3_img.load("images/obstacles/obs3.png");

	/*Load Obstacle 4 Image*/
	std::cout << "#> Load Obstacle 4 Image ...\n";
	obs4_img[0].load("images/obstacles/obs4.png");
	obs4_img[1].load("images/obstacles/obs40.png");

	/*Load Obstacle 41 Image*/
	std::cout << "#> Load Obstacle 41 Image ...\n";
	obs41_img.load("images/obstacles/obs41.png");

	/*Load Obstacle 5 Image*/
	std::cout << "#> Load Obstacle 5 Image ...\n";
	obs5_img.load("images/obstacles/obs5.png");
	
	/*Load Obstacle 5 Image*/
	std::cout << "#> Load Obstacle 50 Image ...\n";
	obs50_img.load("images/obstacles/obs50.png");


	/*Load School Image*/
	std::cout << "#> Load School Image ...\n";
	schoolImg.load("images/school.png");

	/*Load Ment */
	std::cout << "#> Load Ment Widnow ...\n";
	mentWindow.load();

	/*Load Gage */
	gageimg[0].load("images/gage/gagebar.png");
	gageimg[1].load("images/gage/gageframe.png");

	chf[0].load("images/character/ch0.png");
	chf[1].load("images/character/ch2.png");

}
void ofApp::setting() {
	b2Filter f;
	f.categoryBits = 0x00000000;
	
	
	/* Setting FBO*/
	std::cout << "#> Set FBO ... \n";
	fbo.allocate(1920,1080);

	/* Setting Character */ 
	std::cout << "#> Set Character 0 ...\n";
	ch.allocImages(CHARACTER_CRY, 4);
	for (int i = 0; i < 4; i++) {
		ch.addImages(CHARACTER_CRY, ch_cryImages[i]);
	}
	ch.allocImages(CHARACTER_WALK, 3);
	for (int i = 0; i < 3; i++) {
		ch.addImages(CHARACTER_WALK, ch_walkImages[i]);
	}
	
	ch.setPhysics(1, 0, 0);
	ch.setup(box2d.getWorld(),CHARACTER_DEF_X, CHARACTER_DEF_Y, CHARACTER_WIDTH, CHARACTER_HEIGHT);
	ch.setFilterData(f);

	ch.setItemImg(obs41_img, obs50_img);

	/*Setting Sign*/
	signs.allocImages(6);
	for (int i = 0; i < 6; i++) {
		signs.addImages(signImages[i]);
		mentWindow.setSignImg(i, signImages[i]);
		
	}
	mentWindow.setChImg(ch_walkImages[0]);
	signs.setPos(0,283-SIGN_WIDTH/2, 1002-SIGN_HEIGHT);
	signs.setPos(1, 983-SIGN_WIDTH/2, 930-SIGN_HEIGHT);
	signs.setPos(2, 1463-SIGN_WIDTH/2, 800-SIGN_HEIGHT);
	signs.setPos(3, 500 - SIGN_WIDTH / 2, 647 - SIGN_HEIGHT);
	signs.setPos(4, 1644 - SIGN_WIDTH / 2, 415 - SIGN_HEIGHT);
	signs.setPos(5, 651 - SIGN_WIDTH / 2, 418 - SIGN_HEIGHT);


	/* Setting Obstacle 1*/
	std::cout << "#> Set Obstacle 0 ...\n";
	obs0.allocImages(1);
	obs0.addImages(obs0_img);
	obs0.setPhysics(1, 0, 0);
	obs0.setVisible(false);
	obs0.setSize(OBS_0_WIDTH, OBS_0_HEIGHT);
	obs0.setup(box2d.getWorld(), OBS_0_DEF_X, OBS_0_DEF_Y, OBS_0_WIDTH, OBS_0_HEIGHT);
	obs0.setFilterData(f);
	obs0.setDest(CHARACTER_DEF_X + CHARACTER_WIDTH / 2, CHARACTER_DEF_Y + CHARACTER_HEIGHT / 2);


	std::cout << "#> Set Obstacle 1 ...\n";
	obs1.allocImages(1);
	obs1.addImages(obs1_img);
	obs1.setPhysics(0, 0, 0);
	obs1.setVisible(true);
	obs1.setSize(OBS_1_WIDTH, OBS_1_HEIGHT);
	obs1.setup(box2d.getWorld(), OBS_1_DEF_X, OBS_1_DEF_Y, OBS_1_WIDTH, OBS_1_HEIGHT);
	obs1.setFilterData(f);

	std::cout << "#> Set Obstacle 2 ...\n";
	obs2.allocImages(1);
	obs2.addImages(obs2_img);
	obs2.setPhysics(0, 0, 0);
	obs2.setVisible(true);
	obs2.setSize(OBS_2_WIDTH, OBS_2_HEIGHT);
	obs2.setup(box2d.getWorld(), OBS_2_DEF_X, OBS_2_DEF_Y, OBS_2_WIDTH, OBS_2_HEIGHT);
	obs2.setFilterData(f);


	std::cout << "#> Set Obstacle 3 ...\n";
	obs3.allocImages(1);
	obs3.addImages(obs3_img);
	obs3.setPhysics(0, 0, 0);
	obs3.setVisible(false);
	obs3.setSize(OBS_3_WIDTH, OBS_3_HEIGHT);
	obs3.setup(box2d.getWorld(), OBS_3_DEF_X, OBS_3_DEF_Y, OBS_3_WIDTH, OBS_3_HEIGHT);
	obs3.setFilterData(f);

	std::cout << "#> Set Obstacle 4 ...\n";
	obs4.allocImages(2);
	obs4.addImages(obs4_img[0]);
	obs4.addImages(obs4_img[1]);
	obs4.setPhysics(0, 0, 0);
	obs4.setVisible(true);
	obs4.setSize(OBS_4_WIDTH, OBS_4_HEIGHT);
	obs4.setup(box2d.getWorld(), OBS_4_DEF_X, OBS_4_DEF_Y, OBS_4_WIDTH, OBS_4_HEIGHT);
	obs4.setFilterData(f);

	std::cout << "#> Set Obstacle 41 ...\n";
	obs41.allocImages(1);
	obs41.addImages(obs41_img);
	obs41.setPhysics(1, 0, 0);
	obs41.setVisible(false);
	obs41.setSize(OBS_41_WIDTH, OBS_41_HEIGHT);
	obs41.setup(box2d.getWorld(), OBS_41_DEF_X, OBS_41_DEF_Y, OBS_41_WIDTH, OBS_41_HEIGHT);
	obs41.setFilterData(f);


	std::cout << "#> Set Obstacle 5 ...\n";
	obs5.allocImages(1);
	obs5.addImages(obs5_img);
	obs5.setPhysics(0, 0, 0);
	obs5.setVisible(true);
	obs5.setSize(OBS_5_WIDTH, OBS_5_HEIGHT);
	obs5.setup(box2d.getWorld(), OBS_5_DEF_X, OBS_5_DEF_Y, OBS_5_WIDTH, OBS_5_HEIGHT);
	obs5.setFilterData(f);


	std::cout << "#> Set Obstacle 50 ...\n";
	obs50.allocImages(1);
	obs50.addImages(obs50_img);
	obs50.setPhysics(1, 0, 0);
	obs50.setVisible(false);
	obs50.setSize(OBS_50_WIDTH, OBS_50_HEIGHT);
	obs50.setup(box2d.getWorld(), OBS_50_DEF_X, OBS_50_DEF_Y, OBS_50_WIDTH, OBS_50_HEIGHT);
	obs50.setFilterData(f);

	gage.setImg(gageimg[0], gageimg[1]);
	gage.fontSet();
	gage.setChFace(chf[0]);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	//ofSetFrameRate(140);
	checkMsg();
	mentWindow.update();

	if (proCount == 10) {
		sm.playBabam();
		//ch.bub.upgrade();
		switch (progress) {
		case 0:
			obs0.play();
			break;
		case 2:
			obs1.play();
			break;
		case 5:
			obs2.play();
			break;
		case 8:
			obs3.play();
			break;
		case 11:
			obs41.setDest(ch.getPosition().x, ch.getPosition().y);
			obs41.play();
			break;
		case 15:
			obs50.setDest(ch.getPosition().x, ch.getPosition().y);
			obs50.play();
			break;
		}
	}
	if (proCount > 0) {
		proCount--;
	}


	box2d.update();
	ch.update();
	if (progress == 0 && obs0.updateObs()) { //idle
		progress++;
		ch.nextOperation();
		ch.bub.upgrade();
		mentWindow.show(0);
		ch.bub.showMoving();
	}
	if (progress == 1 && ch.getPosition().x>=970-CHARACTER_WIDTH) { //idle
		progress++;
		ch.nextOperation();
		//mentWindow.close();
		ch.bub.closeMoving();
	}
	if (progress == 2 && obs1.updateObs()) {
		progress++;
		mentWindow.close();
		mentWindow.show(1);
		ch.nextOperation();
		ch.bub.upgrade();
		
		ch.bub.showMoving();
	}
	if (progress == 3 && ch.getPosition().x >= 1960 - CHARACTER_WIDTH) {
		progress++;
		ch.nextOperation();
	}
	if (progress == 4 && ch.getPosition().x <= 1640) {
		progress++;
		ch.nextOperation();
		
		ch.bub.closeMoving();
	}
	if (progress == 5 && obs2.updateObs()) { //idle
		progress++;
		ch.nextOperation();
		ch.bub.upgrade();
		mentWindow.close();
		mentWindow.show(2);
		ch.bub.showMoving();
	}
	if (progress == 6 && ch.getPosition().x + CHARACTER_WIDTH / 2 <= 0) {
		progress++;
		ch.nextOperation();
	}
	if (progress == 7 && ch.getPosition().x >= 330) {
		progress++;
		ch.nextOperation();
		
		ch.bub.closeMoving();
	}
	if (progress == 8 && obs3.updateObs()) { //idle
		progress++;
		ch.nextOperation();
		mentWindow.close();
		mentWindow.show(3);
		ch.bub.showMoving();
	}
	if (progress == 9 && ch.getPosition().x>=1820) {
		progress++;
		ch.nextOperation();
	}
	if (progress == 10 && ch.getPosition().x <= 1675) {
		progress++;
		ch.nextOperation();
		
		ch.bub.closeMoving();
	}
	if (progress == 11 && obs41.updateObs()) { //idle
		progress++;
		ch.nextOperation();
		mentWindow.close();
		mentWindow.show(4);
		ch.bub.showMoving();
	}
	if (progress == 12 && (ch.getPosition().x >= OBS_4_DEF_X && ch.getPosition().x <= OBS_4_DEF_X + OBS_4_WIDTH)) {
		progress++;
		ch.draw_item0 = true;
	}
	if (progress == 13 && ch.getPosition().x < OBS_4_DEF_X) {
		progress++;
		ch.draw_item0 = false;
	
	}
	if (progress == 14 && ch.getPosition().x <= 1050) {
		progress++;
		ch.nextOperation();
		
		ch.bub.closeMoving();
	}
	if (progress == 15 && obs50.updateObs()) { //idle
		progress++;
		ch.nextOperation();
		mentWindow.close();
		mentWindow.show(5);
		ch.bub.showMoving();
	}
	if (progress == 16 && (ch.getPosition().x >=OBS_5_DEF_X)) {
		progress++;
		ch.draw_item1 = true;
	}
	if (progress == 17 && ch.getPosition().x < OBS_5_DEF_X) {
		progress++;
		ch.draw_item1 = false;
		
		ch.bub.closeMoving();
	}
	if (progress == 18 && ch.getPosition().x < 250) {
		progress++;
		ch.nextOperation();
		mentWindow.close();
		mentWindow.showEndMent();
	}
	

	obs4.updateObs();
	obs5.updateObs();

	if (mentWindow.game_end) {
		end_ment_idle_tic++;
		if (end_ment_idle_tic > MENT_END_IDLE) {
			end_ment_idle_tic = 0;
			mentWindow.game_end = false;
			mentWindow.closeEndMent();
			nextStage();
		}

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw(0,0);
	
	schoolImg.draw(0, 116);

	obs0.drawObs();
	obs1.drawObs();
	obs2.drawObs();
	obs3.drawObs();
	obs4.drawObs();
	obs5.drawObs();
	obs41.drawObs();
	obs50.drawObs();

	signs.draw();
	ch.draw();

	gage.draw();
	mentWindow.draw();
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
	gage.gageup();
	proCount = 10;
	//mentWindow.show(0);
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

void ofApp::drawToFbo() {
	fbo.begin();
	backImage.draw(0, 0);
	fbo.end();
}

void ofApp::checkMsg() {
	if (proCount > 0)return;

	char recvMsg[100];
	int byteReceived = udpConnection.Receive(recvMsg, 100);
	//std::cout << " :" + to_string(byteReceived) + "\n";
	if (byteReceived > 5) {
		gage.gageup();
		proCount = 10;
	}
}

void ofApp::nextStage() {
	/*ch_type++;
	if (ch_type >= 3)
		ch_type = 0;*/
	if (ch_type == 0) {
		ch_type = 2;
		gage.setChFace(chf[1]);
	}
	else if (ch_type == 2) {
		ch_type = 0;
		gage.setChFace(chf[0]);
	}
	for (int i = 0; i < 4; i++) {
		ch_cryImages[i].clear();
	}
	for (int i = 0; i < 3; i++) {
		ch_walkImages[i].clear();
	}
	std::cout << "#> Load Character  Images ...\n";
	for (int i = 0; i < 4; i++) {
		string path = "images/character/character"+to_string(ch_type)+"/cry"+to_string(ch_type) + to_string(i) + ".png";
		std::cout << path+"\n";
		ch_cryImages[i].load(path);
	}
	for (int i = 0; i < 3; i++) {
		string path = "images/character/character" + to_string(ch_type) + "/walk" + to_string(ch_type) + to_string(i) + ".png";
		ch_walkImages[i].load(path);
		std::cout << path + "\n";
	}
	std::cout << "#> Set Character Images ...\n";
	for (int i = 0; i < 4; i++) {
		ch.setImages(CHARACTER_CRY, i, ch_cryImages[i]);
	}
	for (int i = 0; i < 3; i++) {
		ch.setImages(CHARACTER_WALK, i, ch_walkImages[i]);
	}

	b2Filter f;
	f.categoryBits = 0x00000000;

	ch.setup(box2d.getWorld(), CHARACTER_DEF_X, CHARACTER_DEF_Y, CHARACTER_WIDTH, CHARACTER_HEIGHT);
	ch.setFilterData(f);
	ch.setNext();
	progress = 0;

	/*reset obs0*/
	obs0.setVisible(false);
	obs0.setup(box2d.getWorld(), OBS_0_DEF_X, OBS_0_DEF_Y, OBS_0_WIDTH, OBS_0_HEIGHT);
	obs0.setFilterData(f);
	obs0.resetIdleTic();

	/*reset obs1*/
	obs1.setVisible(true);
	//obs1.drawEffect = false;
	obs1.resetSubInfo();

	/*reset obs2*/
	obs2.setVisible(true);
	//obs2.drawEffect = false;
	obs2.resetSubInfo();

	/*reset obs3*/
	obs3.setVisible(false);
//	obs3.drawEffect = false;
	obs3.resetSubInfo();

	obs41.setVisible(false);
	obs41.setup(box2d.getWorld(), OBS_41_DEF_X, OBS_41_DEF_Y, OBS_41_WIDTH, OBS_41_HEIGHT);
	obs41.setFilterData(f);
	obs41.resetIdleTic();

	obs50.setVisible(false);
	obs50.setup(box2d.getWorld(), OBS_50_DEF_X, OBS_50_DEF_Y, OBS_50_WIDTH, OBS_50_HEIGHT);
	obs50.setFilterData(f);
	obs50.resetIdleTic();

	mentWindow.setChImg(ch_walkImages[0]);
	mentWindow.reset();
}