#ifndef _WavemanSENDER_h
#define _WavemanSENDER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class WavemanSender
{
private:
	void Send();
	void SendIntro();
	void SendElement(bool isOne);
	void SendOne();
	void SendZero();
	void SendHigh(int delay);
	void SendLow(int delay);

public:
	WavemanSender(byte pinId);
	void SendOn(char letter, byte number);
	void SendOff(char letter, byte number);
};