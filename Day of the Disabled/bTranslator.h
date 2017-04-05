#pragma once
#include "ofMain.h"
class bTranslator
{
public:
	bTranslator();
	~bTranslator();
	

	

	
	class book {
	public :
		int char_index=-1;
		string* page;
		void setbook(int pages);
		void setPage(int page, string contents);
	};

	book b1;
	book b2;
	book b3;
	book b4;
	book b5;
	string *titles;
	string * b1_t;
	string *b2_t;
	string *b3_t;
	string *b4_t;
	string *b5_t;
	void makeBook();
};

