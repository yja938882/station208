#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	/*setting box2d*/
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.createGround(0, 1700, 1080, 1700);

	box2d.setFPS(60);
	box2d.registerGrabbing();

	/*load */
	loadImages();
	loadSounds();
	/*setup*/
	fbo.allocate(1080, 1920 * 2);
	gage.setGage();
	setupSun();
	setupAngel();
	setupClouds();
	setupHouse();
	setupTemple();
	/*initial drawing*/
	


	std::cout << "___________________________________________\n";
	std::cout << " # > 현재 : " + to_string(tm.getCurH()) + " : " + to_string(tm.getCurMin());
	
	if (tm.isDay()) {
		std::cout << " [낮] \n";
	}else {
		std::cout << " [밤] \n";
	}
	std::cout << " # > 저장된 기록 : ";
	loaded_num = load();
	std::cout << to_string(loaded_num) + "\n";

	std::cout << " #> 설정 모드 (1)  |  바로 실행 (2)  | 입력 : ";
	std::cin >> mode;
	if (mode == 1) {
		std::cout << " #> 위화면 보기 (1) | 아래화면 보기 (2)  | 입력 : ";
		std::cin >> screen;
		int tH;
		int tM;
		std::cout << " #> 현재 시간 설정 | 시 : ";
		std::cin >> tH;
		std::cout << " #> 현재시간 설정 | 분 : ";
		std::cin >> tM;

		if (tH >= 6 && tH < 18)
			isDay = true;
		else {
			isDay = false;
		}
	}
	else {
		screen = 1;
		isDay = tm.isDay();
	}
	std::cout << " #> 초기값 설정 (1) | 저장된 정보로 설정 (2) | 입력 : ";
	int s;
	std::cin >> s;
	if (s == 1) {
		std::cout << " #> 초기값 입력 : ";
		std::cin >> loaded_num;
		gage.num = loaded_num;
	}
	else {
		loaded_num = load();
		gage.num = loaded_num;
		save(loaded_num);
	}
	drawToFbo();


	setByDay();
	receiver.setup(PORT);
	tm.startTimer();
	
}
void ofApp::loadImages() {
	/*load backgroud Images*/
	std::cout << "#> load background images ...";
	top_back_day.load("images/back/background_day.png");
	bottom_back_day.load("images/back/bottom_day.png");
	top_back_night.load("images/back/background_night.png");
	bottom_back_night.load("images/back/bottom_night.png");
	std::cout << "complete!\n";

	/*load sun Images*/
	std::cout << "#> load sun Images ...";
	sunImage[0].load("images/sun/sun0.png");
	sunImage[1].load("images/sun/sun1.png");
	sunmaneImage.load("images/sun/sun_mane.png");

	moonImage[0].load("images/sun/moon0.png");
	moonImage[1].load("images/sun/moon1.png");
	std::cout << "complete!\n";

	/*load angel Images*/
	std::cout << "#> load angel Images ...";
	leftWingImg.load("images/angel/f0.png");
	rightWingImg.load("images/angel/f1.png");
	angel_0_Image.load("images/angel/angel0.png");
	angel_1_Image.load("images/angel/angel1.png");
	std::cout << "complete!\n";

	/*load cloud Images*/
	std::cout << "#> load Cloud Images ...";
	for (int i = 0; i < CLOUD_NUM; i++) {
		cloudImg[i].load("images/cloud/cloud" + to_string(i) + ".png");
	}
	std::cout << "complete!\n";

	/*load house Images*/
	std::cout << "#> load House Images ...\n";
	for (int i = 0; i < HOUSE_TYPE_NUM * 6; i++) {
		string path = "images/houses/house" + to_string(i / 6) + "_" + to_string(i % 6) + ".png";
		houseImages[i].load(path);
		cout << "load house Img : " + path + "\n";
	}
	std::cout << "comple!\n";

	/*laod bottom house images*/
	std::cout << "#> load Bottom House Images ...\n";
	for (int i = 0; i < HOUSE_TYPE_NUM; i++) {
		string path = "images/bottomhouse/house" + to_string(i) + ".png";
		bottomHouseImages[i].load(path);
	}
	std::cout << "#> complet!\n";

	/*load temple Image*/
	std::cout << "# > load Temple Images ...";
	templeImage.load("images/bottomhouse/temple.png");
	std::cout << "complete!\n";

	/*load temple house Images*/
	std::cout << "# > load Temple Houses Images ...";
	for (int i = 0; i < HOUSE_TYPE_NUM; i++) {
		string path = "images/bottomhouse/house" + to_string(i) + ".png";
		templeHouseImgs[i].load(path);
	}
	std::cout << "complete!\n";

	/*load man Imags*/
	std::cout << "# >load Manual Images ...";
	manImg.load("images/man.png");
	std::cout << "complete!\n";

	/*load font*/
	manfont.loadFont("font/manualfont.ttf", 20, true, true);
	manfont.setLetterSpacing(1);
	manfont.setLineHeight(50);
	
	manfont2.loadFont("font/manualfont.ttf", 22, true, true);
	manfont2.setLetterSpacing(1);
	manfont2.setLineHeight(50);
	
}
void ofApp::loadSounds() {
	next_house_sound.load("sounds/nexthouse.wav");
	block_sound.load("sounds/houseblock.ogg");
}

//이든아이빌은 왕십리에 위치한 지역 아동 복지 센터로, 
//성동구 지역 아이들의 보호와 양육, 교육을 담당하고 있습니다.
//이번 모금은 아이들에게 더 나은 환경을 제공하기 위해 사용됩니다.

void ofApp::setupSun() {
	sun.setmaneImg(sunmaneImage);
	sun.allocImages(2);
	sun.addImages(sunImage[0]);
	sun.addImages(sunImage[1]);

	sun.setPhysics(1, 0, 0);
	sun.setup(box2d.getWorld(), 100, 150, SUN_WIDTH, SUN_HEIGHT);

	b2Filter f;
	f.categoryBits = 0x00000000;
	sun.setFilterData(f);



}
void ofApp::setupAngel() {
	b2Filter f;
	f.categoryBits = 0x00000000;

	angel_0.allocImages(1);
	angel_0.addImages(angel_0_Image);
	angel_0.setPhysics(1, 0, 0);
	angel_0.setup(box2d.getWorld(), 700, 1500, ANGEL_WIDTH, ANGEL_HEIGHT);
	angel_0.setWingImg(leftWingImg, rightWingImg);
	angel_0.setFilterData(f);

	angel_1.allocImages(1);
	angel_1.addImages(angel_1_Image);
	angel_1.setPhysics(1, 0, 0);
	angel_1.setup(box2d.getWorld(), 200, 1500, ANGEL_WIDTH, ANGEL_HEIGHT);
	angel_1.setWingImg(leftWingImg, rightWingImg);
	angel_1.setFilterData(f);

}
void ofApp::setupClouds() {
	b2Filter f;
	f.categoryBits = 0x00000000;

	for (int i = 0; i < CLOUD_NUM; i++) {
		cloud[i].allocImages(1);
		cloud[i].addImages(cloudImg[i]);
		cloud[i].setPhysics(1, 0, 0);
		cloud[i].setup(box2d.getWorld(), rand() % 1000, i * 200 + 200, CLOUD_WIDTH, CLOUD_HEIGHT);
		cloud[i].setVelocity(-1+ofRandom(-0.5, 0.5), 0);
		cloud[i].setFilterData(f);
	}
}
void ofApp::setupHouse() {
	b2Filter f;
	f.categoryBits = 0x00000000;

	curHouse.allocImages(6);
	for (int i = 0; i < 6; i++) {
		curHouse.addImages(houseImages[i+curHouseIndex*6]);
	}
	
	curHouse.setPhysics(1, 0, 0);
	curHouse.setup(box2d.getWorld(), HOUSE_DEF_X, HOUSE_DEF_Y, HOUSE_WIDTH, HOUSE_HEIGHT);
	curHouse.setFilterData(f);

	curHouse.houseBlock.allocImages(1);
	curHouse.houseBlock.setImages(curHouse.images[1] , 0);
	curHouse.houseBlock.setPhysics(1, 0, 0);
	curHouse.houseBlock.setup(box2d.getWorld(), 0, HOUSE_BLOCK_START_Y, HOUSE_WIDTH, HOUSE_HEIGHT);
	curHouse.houseBlock.setFilterData(f);

	bthouse.allocImages(1);
	bthouse.setImages(bottomHouseImages[curHouseIndex],0);
	bthouse.setPhysics(1, 0, 0);
	bthouse.setup(box2d.getWorld(), 0,0, 250, 250);
	
	bthouse.setFilterData(f);
	

}
void ofApp::setupNextHouse(){
	curHouseIndex++;
	if (curHouseIndex >= 9)
		curHouseIndex = 0;
	for (int i = 0; i < 6; i++) {
		curHouse.setImages(houseImages[i + curHouseIndex * 6],i);
	}
	curHouse.houseBlock.setImages(curHouse.images[1], 0);
	curHouse.resetDrawIndex();
	
}
void ofApp::setupTemple() {
	b2Filter f;
	f.categoryBits = 0x00000000;

	for (int i = 0; i < HOUSE_TYPE_NUM; i++) {
		temple.housesImages[i] = templeHouseImgs[i];
	}
	
	temple.allocImages(1);
	temple.addImages(templeImage);
	temple.setPhysics(1, 0, 0);
	temple.setup(box2d.getWorld(), TEMPLE_DEF_X, TEMPLE_DEF_Y, TEMPLE_WIDTH, TEMPLE_HEIGHT);
	temple.setFilterData(f);

	temple.bullet.allocImages(1);
	temple.bullet.setPhysics(1, 0, 0);
	temple.bullet.setup(box2d.getWorld(), TEMPLE_DEF_X, TEMPLE_DEF_Y, 200, 200);
	temple.bullet.setFilterData(f);
	temple.bullet.setDest(bottom_x_for_house[bottom_house_index], bottom_y_for_house[bottom_house_index]+1920-200);
	temple.bullet.addImages(templeHouseImgs[curHouseIndex]);

}


//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(140);
	box2d.update();
	sun.update();
	angel_0.update();
	angel_1.update();
	for (int i = 0; i < CLOUD_NUM; i++) {
		cloud[i].update();
	}

	osc208();
	if (bang != 0 && abb == 0 && completeCounter == -1) {
		abb = 1;
		proc();
	}


	if (curHouse.updateHouse()) {//set Next House
		std::cout << "Set Next House!!\n";
		temple.bullet.processing = true;
		next_house_sound.play();
		bottom_house_index++;
	

		setupNextHouse();
		
	}

	if (temple.bullet.ntrset) {
		if (bottom_house_index >= 27) {
			bottom_house_index = 0;
			drawToFbo();
			//std::cout << "after dfb\n";
		}
		if(bottom_house_index!=0)
			drawBottomHouseToFbo();
		temple.bullet.setDest(bottom_x_for_house[bottom_house_index], bottom_y_for_house[bottom_house_index] + 1920 - 200);
		temple.bullet.setImages(templeHouseImgs[curHouseIndex], 0);
		temple.bullet.ntrset = false;
	}


	if (curHouse.houseBlock.processing) {
		angel_0.gotoDest(
			curHouse.houseBlock.getPosition().x + bbx_for_an0[curHouseIndex*5+curHouseBlockIndex],
			curHouse.houseBlock.getPosition().y + bby_for_ang[curHouseIndex*5+curHouseBlockIndex]
		);
		angel_1.gotoDest(
			curHouse.houseBlock.getPosition().x+bbx_for_an1[curHouseIndex * 5 + curHouseBlockIndex] - ANGEL_WIDTH,
			curHouse.houseBlock.getPosition().y+bby_for_ang[curHouseIndex * 5 + curHouseBlockIndex]
		);
	}
	else {
		angel_0.gotoDest(ANGEL_0_DEF_X, ANGEL_DEF_Y);
		angel_1.gotoDest(ANGEL_1_DEF_X, ANGEL_DEF_Y);
	}
	temple.bullet.updateBullet();
	
	if (tm.getTimerCount() >= 60) {
		bool tday = tm.isDay();
		if (tday != isDay) {
			isDay = tm.isDay();
			drawToFbo();
			setByDay();
			
		}
		tm.startTimer();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofRotate(-90);
	ofTranslate(-1080, 0, 0);

	if (screen == 2) {
		ofTranslate(0, -1920, 0);
	}

	/*draw fbo*/
	fbo.draw(0,0);

	/*draw Gage*/
	gage.draw();

	/*draw Clouds*/
	for (int i = 0; i < CLOUD_NUM; i++) {
		cloud[i].draw();
	}

	/*draw sun*/
	sun.draw();
	sun.drawMane();

	/*draw house*/
	curHouse.cumDraw();
	if(curHouse.houseBlock.visible)
		curHouse.houseBlock.draw();
	/*draw angel*/
	angel_0.drawWing();
	angel_0.draw(ANGEL_WIDTH,ANGEL_HEIGHT);
	angel_1.drawWing();
	angel_1.draw(ANGEL_WIDTH,ANGEL_HEIGHT);

	/*draw temple*/
	temple.draw();
	if (temple.bullet.processing) {
		temple.drawEffect();
		temple.bullet.draw(200,200);
		
	}
	else {
		temple.bullet.resetIdle();
	}
}

void ofApp::drawToFbo() {
	fbo.begin();
	if (isDay) {
		top_back_day.draw(0, 0);
		bottom_back_day.draw(0, 1920);
	}
	else {
		top_back_night.draw(0, 0);
		bottom_back_night.draw(0, 1920);
	}
	manImg.draw(0, 1920);

	ofSetHexColor(0x000000);
	manfont.drawString(manSmall,100,2000);
	manfont2.drawString(manBig, 100, 2150);
	ofSetHexColor(0xffffff);

	fbo.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'f') {
		ofToggleFullscreen();
	}
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
void ofApp::drawBottomHouseToFbo() {
	fbo.begin();
	int i = bottom_house_index - 1;
	temple.housesImages[i%9].draw(bottom_x_for_house[i],1920+bottom_y_for_house[i]-200,200,200);
	fbo.end();
}

void ofApp::setByDay() {
	if (isDay) {
		sun.setImages(sunImage[0], 0);
		sun.setImages(sunImage[1], 1);
		sun.day = true;
	}
	else {
		sun.setImages(moonImage[0], 0);
		sun.setImages(moonImage[1], 1);
		sun.day = false;
	}
	fbo.begin();
	for (int i = 0; i < bottom_house_index;i++) {
		temple.housesImages[i % 9].draw(bottom_x_for_house[i], 1920 + bottom_y_for_house[i] - 200, 200, 200);
	}
	fbo.end();

}

void ofApp::save(int num) {
	ofstream outFile("save_data.txt");
	outFile << to_string(num);
	outFile.close();
}
int ofApp::load() {
	ifstream inFile("save_data.txt");
	char str[5];
	inFile >> str;
	inFile.close();
	return atoi(str);
}
void ofApp::osc208() {
	bang = 0;
	while (receiver.hasWaitingMessages()) {

		ofxOscMessage m;
		receiver.getNextMessage(&m);

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
		if (abbco > 200) {
			abb = 0; abbco = 0;
		}
	}
}
void ofApp::proc() {

	gage.upGage();
	//curHouse.upgrade();
	block_sound.play();
	curHouseBlockIndex++;
	if (curHouseBlockIndex >= 5)
		curHouseBlockIndex = 0;
	curHouse.houseBlock.visible = true;
	curHouse.houseBlock.processing = true;


	save(gage.num);
}