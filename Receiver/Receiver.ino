#include "WavemanDecoder.h"
#include "WavemanReceiver.h"

void setup()
{

}

void loop()
{
	Receive();
}

void Receive()
{
	String val = WavemanReceiver(8).Receive();
	Serial.println(val);
	Serial.println("");
	delay(1000);
}