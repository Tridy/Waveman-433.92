#ifndef _WAVEMANDECODER_h
#define _WAVEMANDECODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class WavemanDecoder
{

public:
	WavemanDecoder();
	String DecodeValues(bool readValues[]);

private:
	String _result;

	String GetFourLetterValueStartingFromIndex(byte index);
	String GetSymbolFromReadValuesIndex(byte index);
	String GetLetterFromFourSymbolsCode(String code);
	String GetNumberFromFourSymbolsCode(String code);
	byte GetMatchingMappingIndex(String itemToMatch);
	String GetOnOffValue();
};