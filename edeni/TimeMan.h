#pragma once
#include <ctime>
class TimeMan
{
public:
	time_t curr_time;
	struct tm *curr_tm;
	clock_t start;
	clock_t end;

	TimeMan();
	~TimeMan();
	void setCurrentTime();
	int getCurH();
	int getCurMin();
	bool isDay();

	void startTimer();
	int getTimerCount();
};

