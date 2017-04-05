#include "bTranslator.h"



bTranslator::bTranslator()
{
}


bTranslator::~bTranslator()
{
}
void bTranslator::makeBook() {
	titles = new string[5];
	titles[0] = "-�����-";
	titles[1] = "-���̿� ŷ-";
	titles[2] = "-�̻��� ������ ������-";
	titles[3] = "-�ξ����-";
	titles[4] = "-������ ������-";
	b1_t = new string[2];
	b2_t = new string[2];
	b3_t = new string[2];
	b4_t = new string[2];
	b5_t = new string[2];

	b1_t[0] = "���� �������θ� \n�и��ϰ�\n�� �� �־�, ";
	b1_t[1] = "���� �߿��� ���� \n��͵�\n���� ������ �ʾ�.";
	b2_t[0] = "�ʴ� ���ŷκ��� \n����ĥ ���� �ְ�,";
	b2_t[1] = "���ŷκ��� \n��� ���� �־�.";
	b3_t[0] = "������ ���ư��� ���� \n�ҿ����,";
	b3_t[1] = "���� ������ ���� \n�ٸ� ����̰ŵ�.";
	b4_t[0] = "���� �� ����,";
	b4_t[1] = "���� �� �޿�\n�ӹ����� �Ѵٰ� �ߴ�?";
	b5_t[0] = "������ ���� \n";
	b5_t[1] = "�η��ﶧ ��鸰��.";


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