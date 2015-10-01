// WavemanEncoder.h

#ifndef _WAVEMANENCODER_h
#define _WAVEMANENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class WavemanEncoder
{
private:
	void EncodeLetter(char letter);
	void EncodeNumber(byte number);
	void EncodeOnOf(bool isOn);
	void SetValuesFromOffsetAndValuesArrayStartingIndex(byte mappingsOfset, byte valuesStartingIndex);

public:
	WavemanEncoder();
	void Encode(bool values[], char letter, byte number, bool isOn);
};
