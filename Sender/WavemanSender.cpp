#include "WavemanSender.h"
#include "WavemanEncoder.h"


byte _pinId;
const int LONG_LENGTH = 1260;
const int SHORT_LENGTH = 370;
bool _values[14];

WavemanSender::WavemanSender(byte pinId)
{
	_pinId = pinId;
}

void WavemanSender::SendOn(char letter, byte number)
{
	WavemanEncoder().Encode(_values, letter, number, true);
	Send();
}

void WavemanSender::SendOff(char letter, byte number)
{
	WavemanEncoder().Encode(_values, letter, number, false);
	Send();
}

void WavemanSender::Send()
{
	pinMode(_pinId, OUTPUT);

	for (size_t i = 0; i < 4; i++)
	{
		SendIntro();

		for (size_t i = 0; i < 12; i++)
		{
			SendElement(_values[i]);
		}
	}
}

void WavemanSender::SendIntro()
{
	digitalWrite(_pinId, HIGH);
	delayMicroseconds(420);
	digitalWrite(_pinId, LOW);
	delayMicroseconds(14000);
}

void WavemanSender::SendElement(bool isOne)
{
	if (isOne)
	{
		SendOne();
	}
	else
	{
		SendZero();
	}
}

void WavemanSender::SendOne()
{
	SendHigh(SHORT_LENGTH);
	SendLow(LONG_LENGTH);

	SendHigh(LONG_LENGTH);
	SendLow(SHORT_LENGTH);
}

void WavemanSender::SendZero()
{
	for (size_t i = 0; i < 2; i++)
	{
		SendHigh(SHORT_LENGTH);
		SendLow(LONG_LENGTH);
	}
}

void WavemanSender::SendHigh(int delay)
{
	digitalWrite(_pinId, HIGH);
	delayMicroseconds(delay);
}

void WavemanSender::SendLow(int delay)
{
	digitalWrite(_pinId, LOW);
	delayMicroseconds(delay);
}