#include "WavemanDecoder.h"
#include "WavemanReceiver.h"
void setup()
{

}

void loop()
{
	String val = WavemanReceiver(8).Receive();
	Serial.println(val);
	Serial.println("");
	delay(1000);
}