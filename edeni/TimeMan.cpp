#include "TimeMan.h"

#include <cstdio>

TimeMan::TimeMan()
{
}


TimeMan::~TimeMan()
{
}

void TimeMan::setCurrentTime() {
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
}

int TimeMan::getCurH() {
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	return (int)(curr_tm->tm_hour);
}

int TimeMan::getCurMin() {
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	return (int)(curr_tm->tm_min);
}

bool TimeMan::isDay() {
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	if (curr_tm->tm_hour >= 6 && curr_tm->tm_hour < 18) {
		return true;
	}
	return false;
}
void TimeMan::startTimer() {
	start = clock();
}
int TimeMan::getTimerCount() {
	end = clock();
	return (int)( (double) (end - start) / (double)CLOCKS_PER_SEC );
}