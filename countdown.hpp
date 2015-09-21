#ifndef COUNTDOWN_HPP_
#define COUNTDOWN_HPP_

#include <iostream>
#include <time.h>
#include <pthread.h>

using namespace std;

class Countdown
{
public:
	Countdown(int);
	void start();
	void stop();
	
private:
	int min;
	pthread_t process;
};

#endif