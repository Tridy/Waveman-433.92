#include "WavemanSender.h"
void setup()
{

}

void loop()
{
	Send();
}

void Send()
{
	WavemanSender(11).SendOn('M', 1);
	delay(1000);
	WavemanSender(11).SendOff('M', 1);
	delay(1000);
}