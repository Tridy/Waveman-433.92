#include "WavemanReceiver.h"
#include "WavemanDecoder.h"


const int LONG_MIN_LENGTH = 700;
const int LOW_INTRO_LENGTH = 10000;

const int MaxReadingsCount = 65;

WavemanReceiver::WavemanReceiver(int pinId)
{
	ResetVariables();
	pinMode(pinId, INPUT);
	_pinId = pinId;
}

String WavemanReceiver::Receive()
{
	ResetVariables();
	ReceiveSignal();
	
	_receivedResult = WavemanDecoder().DecodeValues(_readValues);
	return _receivedResult;
}

void WavemanReceiver::ResetVariables()
{
	_counter = 0;
	_timing = 0;
}

void WavemanReceiver::ReceiveSignal()
{
	WaitForLongLow();
	ReadValues();
}

void WavemanReceiver::WaitForLongLow()
{
	_timing = 0;

	while (_timing < LOW_INTRO_LENGTH)
	{
		_timing = pulseIn(_pinId, LOW, 1000000);
	}
}

void WavemanReceiver::ReadValues()
{
	unsigned long low = 0;
	unsigned long lastLow = micros();
	unsigned long high = 0;

	while (low < 10000 && _counter < 70)
	{
		low = pulseIn(_pinId, LOW, 1000000);
		high = micros() - (lastLow + low);

		//if (low < 250 || high < 250)
		//{
		//	_hasErrors = true;
		//}

		lastLow = micros();

		_readValues[_counter] = high > LONG_MIN_LENGTH;
		_readValues[_counter + 1] = low > LONG_MIN_LENGTH;

		_counter += 2;
	}
}