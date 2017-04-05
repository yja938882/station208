#include "ofApp.h"
#include "ofMath.h"
//--------------------------------------------------------------
void ofApp::setup(){
	box2d.init();
	box2d.setGravity(0, 20);
	box2d.createGround();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
	ofSetVerticalSync(false);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
	letter_of_word_nums = new int[100];
	word_num =0;

	braille_set.load_Brailles();

	BRAILLE_WIDTH = 100;
	BRAILLE_HEIGHT = 150;
	SPACE_WIDTH = BRAILLE_WIDTH/3;
	INTERVAL_WIDTH = -10;
	INTERVAL_HEIGHT = 0;
	FONT_SIZE = (BRAILLE_WIDTH * 2) / 3;
	LINE_LETTER_NUM = 10;

	progGage.setGage();
	std::cout << "gage ok\n";
	bookfont_large.loadFont("font/crayonfont2.ttf", FONT_SIZE, true, true);
	bookfont_large.setLetterSpacing(1);

	trans.makeBook();

	letters.reserve(48);
	setLetters();


	sManager.loadSounds();

	pen.setupDrawingTool(1040 / 2, 800);
	pen.setPhysics(0, 0, 0);
	pen.setup(box2d.getWorld(), 1040 / 2, 800, pen.w, pen.h);
	
	backcolor.set(255, 255, 255);

	redstarImg.load("images/redstar.png");
	yellowstarImg.load("images/yellowstar.png");
	bluestarImg.load("images/bluestar.png");
	setStars();

	manualImg.load("images/ui/manual.png");
	manfont.loadFont("font/gagefont.ttf", 20, true, true);
	manfont.setLetterSpacing(1);
	manfont.setLineHeight(50);

	manfont2.loadFont("font/gagefont.ttf", 35, true, true);
	manfont.setLetterSpacing(1);
	manfont.setLineHeight(50);

	ofSetBackgroundColor(backcolor);


	fbo.allocate(1080, 1920 * 2);
	book_ir.setImg();
	book_ir.setPos(0, 3840-801, 1080, 801);
	book_ir.setFont();
	bgImg.load("images/b1img.png");
	

	drawToFbo();

	std::cout<< "\n ";
	std::cout<< " > 위에 화면 보기 (1)\n";
	std::cout<< " > 아래 화면 보기 (2)\n";
	std::cout<< " > 입력 : ";
	std::cin >> t;
	std::cout << " > Frame  rate (max for 0)\n";
	std::cout << " > 입력 :";
	std::cin >> frame_r;

	receiver.setup(PORT);
	bang = 0;
	ofHideCursor();

	addbook.load("images/addbook.png");

}

//--------------------------------------------------------------
void ofApp::update(){

	if(!(frame_r==0))
		ofSetFrameRate(frame_r);
	std::stringstream strm;
	 	strm << "fps: " << ofGetFrameRate();
	 	ofSetWindowTitle(strm.str());




	box2d.update();
	
	ofSoundUpdate();

	//if (!(sManager.back.isPlaying()))
		//sManager.playSound(soundManager::BACK_SOUND);
	tick_count++;
	if (tick_count == 500 && !word_writing && completeCounter==-1) {
		pen.stop_spin = true;
		scatterStars();
	}

	if (tick_count >= 600)
		tick_count = 0;

	if (w_index >= word_num) {
		if(current_page==0)
			book_ir.p1_han = true;
		else
			book_ir.p2_han = true;
	}
	
	osc208();
	if (bang != 0 && abb == 0 &&completeCounter==-1) {
		abb = 1;
		if (word_writing)return;
		if (c_index <= c_endIndex)return;
		
		sManager.playSound(soundManager::TAG1_SOUND);;
		writingWord();
		scatterStars();
		test = true;

		progGage.upGage();
		drawToFbo();

	}

	updateWriting();

	int te=0;
	for (int i = 0; i < letters.size(); i++) {
		if (letters[i].get()->update_() == 1) {
			te = 1;	
		}
	}
	pen.update();
	

	if ((w_index >= word_num)&&te==1) {
		if (current_page == 1) {
			completeCounter = 900;
			stars_show = true;
			fbo.begin();
			ofClear(255, 255, 255, 0);
			fbo.end();
		}
		else {
			completeCounter = 0;
		}
	}
	if (completeCounter > 0) {
		if (completeCounter % 200 == 0) {
			int rx = ofRandom(-10, 10);
			scatterStars(book_ir.posX + 540+rx*10, book_ir.posY + comdp + 350+ rx * 10);
		}
		completeCounter--;
	}
	if (completeCounter == 0) {
			if (current_page == 0) {
				current_word += ("" + letters[c_index].get()->c + "" + letters[c_index].get()->additional);
				book_ir.setString(current_word);
			}

		stars_show = true;
		completeCounter = -1;
		resetLetters();
		w_index = 0;
		drawToFbo();
	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetHexColor(0xffffff);
	ofRotateZ(-90);
	ofTranslate(-1080,0, 0);

	if(t==2)
		ofTranslate(0, -1920, 0);


	

	fbo.draw(0, 0);

	if (completeCounter < 0) {
		for (int i = 0; i < letters.size(); i++) {
			letters[i].get()->draw();
		}
		pen.draw();
		ofSetHexColor(0xffffff);
		if (stars_show) {
			for (int i = 0; i < stars.size(); i++) {
				stars[i].get()->draw();

			}
		}
		comdp = 0;
		rad = 300;
		alp = 255;
	}
	else if(completeCounter>0){
		if(completeCounter>=400)
				comdp -=5;
		if (completeCounter <= 255) {
			alp--;
			if (alp < 0)
				alp = 0;
		}

		if ((completeCounter / 40) % 2 == 0)
			rad += dr;
		else
			rad -= dr;
		int talp = alp - 15;
		if (talp < 0)
			talp = 0;
		ofSetColor(ofColor::lightGoldenRodYellow, talp);
		ofFill();
		ofSetCircleResolution(100);
		ofCircle(book_ir.posX + 520, book_ir.posY + comdp + 350, rad);
		
		ofSetColor(ofColor::white, alp);
		book_ir.draw(0, comdp,alp);
		
		ofSetHexColor(0xffffff);
		progGage.draw();
		ofSetHexColor(0xffffff);
		
		
		if (stars_show) {
			for (int i = 0; i < stars.size(); i++) {
				stars[i].get()->draw();

			}
		}
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

void ofApp::setLetters() {

	
	current_word = "";
	current_string = "";
	string c = trans.b1.page[0];
	int posX = 0;
	int posY = 180;
	int word_count = 0;
	int char_count = 0;

	for (int i = 0; i < c.length(); i++) {
		char temp = c.at(i);
		std::cout << temp;

		if (temp == '\n') {
			posY += (BRAILLE_HEIGHT * 2) + INTERVAL_HEIGHT;
			posX = 0;
			current_string +="\n";
			letters.back().get()->additional += '\n';
		}
		else if (temp == '_') {
			posX += SPACE_WIDTH;
			letter_of_word_nums[word_count] = char_count;
			word_count++;
			char_count = 0;
			current_string +=" ";
			letters.back().get()->additional += ' ';
		}
		else{
			char_count++;
			letters.push_back(shared_ptr < CustomParticle>(new CustomParticle));
			current_string += temp;
			char b;
			if (temp >= 'A' && temp <= 'Z') {
				b = temp + ('a' - 'A');
			}
			else {
				b = temp;
			}

			letters.back().get()->setupCustom(*braille_set.getBraille(b), posX, posY, BRAILLE_WIDTH, BRAILLE_HEIGHT, &bookfont_large);
			letters.back().get()->setPhysics(0, 0, 0);
			letters.back().get()->setup(box2d.getWorld(), posX, posY, BRAILLE_WIDTH, BRAILLE_HEIGHT);
			b2Filter f;
			f.categoryBits = 0x00000000;
			letters.back().get()->setFilterData(f);
			stringstream ss;
			ss << temp;
			ss >> letters.back().get()->c;
			posX += (BRAILLE_WIDTH + INTERVAL_WIDTH);

		}
	}
	word_num = word_count;

	book_ir.setTitle(trans.titles[current_book]);
	book_ir.ttohan = "";
	book_ir.ttohan2 = "";

	if (current_book == 0) {
		book_ir.ttohan = trans.b1_t[0];
		book_ir.ttohan2 = trans.b1_t[1];
	}
	else if (current_book == 1) {
		book_ir.ttohan = trans.b2_t[0];
		book_ir.ttohan2 = trans.b2_t[1];
	}
	else if (current_book == 2) {
		book_ir.ttohan = trans.b3_t[0];
		book_ir.ttohan2 = trans.b3_t[1];
	}
	else if (current_book == 3) {
		book_ir.ttohan = trans.b4_t[0];
		book_ir.ttohan2 = trans.b4_t[1];;
	}
	else if (current_book == 4) {
		book_ir.ttohan = trans.b5_t[0];
		book_ir.ttohan2 = trans.b5_t[1];
	}
}

void ofApp::resetLetters() {


	bgImg.clear();
	current_word = "";
	current_string = "";
	current_page++;
	if (current_page >= 2) {
		current_book++;
		current_page = 0;
	}
	if (current_book >= 5)
		current_book = 0;

	string c;
	if (current_book == 0) { 
		c = trans.b1.page[current_page];
		bgImg.load("images/b1img.png");
	}
	else if(current_book ==1){
		c = trans.b2.page[current_page];
		bgImg.load("images/b2img.png");
	}
	else if (current_book == 2) {
		c = trans.b3.page[current_page];
		bgImg.load("images/b3img.png");
	}
	else if (current_book == 3) {
		c = trans.b4.page[current_page];
		bgImg.load("images/b4img.png");
	}
	else if (current_book == 4) {
		c = trans.b5.page[current_page];
		bgImg.load("images/b5img.png");
	}

	letters.clear();

	int posX = 0;
	int posY = 180;
	int word_count = 0;
	int char_count = 0;

	for (int i = 0; i < c.length(); i++) {
		char temp = c.at(i);

		if (temp == '\n') {
			posY += (BRAILLE_HEIGHT * 2) + INTERVAL_HEIGHT;
			posX = 0;
			current_string += "\n";
			letters.back().get()->additional += '\n';
		}
		else if (temp == '_') {
			posX += SPACE_WIDTH;
			letter_of_word_nums[word_count] = char_count;
			word_count++;
			char_count = 0;
			current_string + " ";
			letters.back().get()->additional += ' ';
		}
		else {
			char_count++;
			letters.push_back(shared_ptr < CustomParticle>(new CustomParticle));
			
			current_string += temp;
			char b;
			if (temp >= 'A' && temp <= 'Z') {
				b = temp + ('a' - 'A');
			}
			else {
				b = temp;
			}

			letters.back().get()->setupCustom(*braille_set.getBraille(b), posX, posY, BRAILLE_WIDTH, BRAILLE_HEIGHT, &bookfont_large);
			letters.back().get()->setPhysics(0, 0, 0);
			letters.back().get()->setup(box2d.getWorld(), posX, posY, BRAILLE_WIDTH, BRAILLE_HEIGHT);
	

			b2Filter f;
			f.categoryBits = 0x00000000;
			letters.back().get()->setFilterData(f);
			stringstream ss;
			ss << temp;
			ss >> letters.back().get()->c;
			posX += (BRAILLE_WIDTH + INTERVAL_WIDTH);
			

		}
	}
	word_num = word_count;
	c_index = 0;
	c_endIndex = -1;
	if (current_page == 0) {
		book_ir.resetString();
		book_ir.setTitle(trans.titles[current_book]);
		book_ir.ttohan = "";
		book_ir.ttohan2 = "";

		if (current_book == 0) {  
			book_ir.ttohan = trans.b1_t[0];
			book_ir.ttohan2 = trans.b1_t[1];
		}
		else if (current_book == 1) {
			book_ir.ttohan = trans.b2_t[0];
			book_ir.ttohan2 = trans.b2_t[1];
		}
		else if (current_book == 2) { 
			book_ir.ttohan = trans.b3_t[0];
			book_ir.ttohan2 = trans.b3_t[1];
		}
		else if (current_book == 3) {
			book_ir.ttohan = trans.b4_t[0];
			book_ir.ttohan2 = trans.b4_t[1];; }
		else if (current_book == 4) {
			book_ir.ttohan = trans.b5_t[0];
			book_ir.ttohan2 = trans.b5_t[1];
		}
	}
}

void ofApp::writingWord() {
	c_endIndex = c_index + letter_of_word_nums[w_index]-1;

	for (int i = c_index; i < c_index+letter_of_word_nums[w_index]; i++) {
		letters[i].get()->tagged = true;
	
	}
	letters[c_index].get()->writing_p = true;

	w_index++;
}

void ofApp::updateWriting() {
	
	if (c_index >= letters.size())
		return;
	if (letters[c_index].get()->tagged) {
		if (letters[c_index].get()->writing_p) {
			return;
		}
		c_index++;
		if (c_index < letters.size()) {
			letters[c_index].get()->writing_p = true;
				pen.startWriting(letters[c_index].get()->getPosition().x + 30, letters[c_index].get()->getBottomY() - 30, 20, 70);
				
				current_word += ("" + letters[c_index-1].get()->c + "" + letters[c_index-1].get()->additional);
				if (current_page == 0) {
					book_ir.setString(current_word);
				}
				else {
					book_ir.setString2(current_word);
				}
				drawToFbo();
		
		}
		if (c_index == letters.size()) {
			current_word += ("" + letters[c_index - 1].get()->c + "" + letters[c_index - 1].get()->additional);
			if (current_page == 0) {
				book_ir.setString(current_word);
			}
			else {
				book_ir.setString2(current_word);
			}
		}

		
	}
	
}

void ofApp::setStars() {

	for (int i = 0; i < 18; i++) {
		if (i < 7) {
			stars.push_back(shared_ptr<scatterEffecter>(new scatterEffecter));
			stars.back().get()->setImage(redstarImg);
		}else if(i<14) {
			stars.push_back(shared_ptr<scatterEffecter>(new scatterEffecter));
			stars.back().get()->setImage(yellowstarImg);
		}
		else {
			stars.push_back(shared_ptr<scatterEffecter>(new scatterEffecter));
			stars.back().get()->setImage(bluestarImg);
		}
	}
	for (int i = 0; i < 18; i++) {
		stars[i].get()->setPhysics(1, 0, 0);
		stars[i].get()->setup(box2d.getWorld(), 0, 0, 50, 50);

		b2Filter f;
		f.categoryBits = 0x0;
		stars[i].get()->setFilterData(f);
	}
}



void ofApp::scatterStars() {
	//stars_show = true;
	float x=pen.getPosition().x;
	float y = pen.getPosition().y;
	for (int i = 0; i < 18; i++) {
		stars[i].get()->setPosition(pen.getPosition());
		v.set(ofRandom(-15,15), ofRandom(-20,-40));
		stars[i].get()->addForce(v, 100);
	}
}
void ofApp::scatterStars(int x, int y) {
	//stars_show = true;
	for (int i = 0; i < 18; i++) {
		stars[i].get()->setPosition(x,y);
		v.set(ofRandom(-15, 15), ofRandom(-20, -40));
		stars[i].get()->addForce(v, 100);
	}
}


void ofApp::drawToFbo() {
	fbo.begin();
	ofClear(255, 255, 255, 0);
	ofColor(backcolor);
	bgImg.draw(0, 1960);
	for (int i = 0; i < letters.size(); i++) {
		letters[i].get()->drawString();
	}
	ofSetHexColor(0xffffff);
	progGage.draw();
	manualImg.draw(0, 1360, 1080,560 );
	ofSetHexColor(0x000000);
	
	manfont.drawString(manualString, 30, 1466);

	manfont2.drawString(manualString2, 30, 1676);
	ofSetHexColor(0xffffff);
	book_ir.draw();

	fbo.end();

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

void ofApp::drawForComplete() {
	fbo.begin();
	ofClear(255, 255, 255, 10);
	for (int i = 0; i < letters.size(); i++) {
		letters[i].get()->draw();
	}
	book_ir.draw();
	bgImg.draw(0, 1960);
	for (int i = 0; i < letters.size(); i++) {
		letters[i].get()->drawString();
	}
	ofSetColor(255, 255, 255,0);
	fbo.end();
}

