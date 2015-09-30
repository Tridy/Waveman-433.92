// WavemanReceiver.h

#ifndef _WAVEMANRECEIVER_h
#define _WAVEMANRECEIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class WavemanReceiver
{

public:
	WavemanReceiver(int pinId);
	String Receive();

private:

	unsigned long _timing;
	bool _readValues[100];
	String _receivedResult;
	int _pinId;
	byte _counter;

	void ResetVariables();
	void ReceiveSignal();
	void WaitForLongLow();
	void ReadValues();
};