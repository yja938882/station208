#include "bTranslator.h"



bTranslator::bTranslator()
{
}


bTranslator::~bTranslator()
{
}
void bTranslator::makeBook() {
	titles = new string[5];
	titles[0] = "-어린왕자-";
	titles[1] = "-라이온 킹-";
	titles[2] = "-이상한 나라의 엘리스-";
	titles[3] = "-인어공주-";
	titles[4] = "-오즈의 마법사-";
	b1_t = new string[2];
	b2_t = new string[2];
	b3_t = new string[2];
	b4_t = new string[2];
	b5_t = new string[2];

	b1_t[0] = "오직 마음으로만 \n분명하게\n볼 수 있어, ";
	b1_t[1] = "정말 중요한 것은 \n어떤것도\n눈에 보이지 않아.";
	b2_t[0] = "너는 과거로부터 \n도망칠 수도 있고,";
	b2_t[1] = "과거로부터 \n배울 수도 있어.";
	b3_t[0] = "어제로 돌아가는 것은 \n소용없어,";
	b3_t[1] = "나는 어제의 나와 \n다른 사람이거든.";
	b4_t[0] = "누가 내 꿈을,";
	b4_t[1] = "그저 내 꿈에\n머물러야 한다고 했니?";
	b5_t[0] = "진정한 용기는 \n";
	b5_t[1] = "두려울때 흔들린다.";


	string data="";
	string temp;
	ifstream readStream;
	/*====================================================*/
	b1.setbook(2);

	readStream.open(ofToDataPath("text/book1_p1.txt"));
	std::cout << "book1 page1:";
	while (getline(readStream,temp)) {
		data += (temp+'\n');
	}
	readStream.close();
	b1.setPage(0, data);


	data = "";
	readStream.open(ofToDataPath("text/book1_p2.txt"));
	std::cout << "book1 page2 :\n";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b1.setPage(1, data);
	/*====================================================*/
	b2.setbook(2);

	data = "";
	readStream.open(ofToDataPath("text/book2_p1.txt"));
	std::cout << "book2 page1:";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b2.setPage(0, data);


	data = "";
	readStream.open(ofToDataPath("text/book2_p2.txt"));
	std::cout << "book2 page2 :\n";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b2.setPage(1, data);
	/*====================================================*/
	b3.setbook(2);

	data = "";
	readStream.open(ofToDataPath("text/book3_p1.txt"));
	std::cout << "book3 page1:";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b3.setPage(0, data);


	data = "";
	readStream.open(ofToDataPath("text/book3_p2.txt"));
	std::cout << "book3 page2 :\n";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b3.setPage(1, data);
	/*====================================================*/
	b4.setbook(2);

	data = "";
	readStream.open(ofToDataPath("text/book4_p1.txt"));
	std::cout << "book4 page1:";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b4.setPage(0, data);


	data = "";
	readStream.open(ofToDataPath("text/book4_p2.txt"));
	std::cout << "book4 page2 :\n";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b4.setPage(1, data);
	/*====================================================*/
	b5.setbook(2);

	data = "";
	readStream.open(ofToDataPath("text/book5_p1.txt"));
	std::cout << "book5 page1:";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b5.setPage(0, data);


	data = "";
	readStream.open(ofToDataPath("text/book5_p2.txt"));
	std::cout << "book5 page2 :\n";
	while (getline(readStream, temp)) {
		data += (temp + '\n');
	}
	readStream.close();
	b5.setPage(1, data);

}

void bTranslator::book::setbook(int pages) {
	page = new string[pages];
}
void bTranslator::book::setPage(int page, string content) {
	(this->page)[page] = content;
}