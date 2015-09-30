#include "WavemanDecoder.h"

bool *_readValues;
String _mappings [] = { "0000", "X000", "0X00", "XX00", "00X0", "X0X0", "0XX0", "XXX0", "000X", "X00X", "0X0X", "XX0X", "00XX", "X0XX", "0XXX", "XXXX" };

WavemanDecoder::WavemanDecoder()
{

}

String WavemanDecoder::DecodeValues(bool readValues[])
{
	_readValues = readValues;

	String letter = GetFourLetterValueStartingFromIndex(2);
	letter = GetLetterFromFourSymbolsCode(letter);

	String number = GetFourLetterValueStartingFromIndex(18);
	number = GetNumberFromFourSymbolsCode(number);

	String on = GetOnOffValue();
	
	return "Letter:" + letter +
		   "\nNumber:" + number + 
		   "\n" + on;
}

String WavemanDecoder::GetFourLetterValueStartingFromIndex(byte index)
{
	String fourLetters = GetSymbolFromReadValuesIndex(index) +
		GetSymbolFromReadValuesIndex(index + 4) +
		GetSymbolFromReadValuesIndex(index + 8) +
		GetSymbolFromReadValuesIndex(index + 12);

	return fourLetters;
}

String WavemanDecoder::GetSymbolFromReadValuesIndex(byte index)
{
	return _readValues[index] ? "X" : "0";
}

String WavemanDecoder::GetLetterFromFourSymbolsCode(String code)
{
	byte matchingIndex = GetMatchingMappingIndex(code);

	if (matchingIndex < 0)
	{
		return "ERROR";
	}

	int a = (int)'A';
	a = a + matchingIndex;
	char letterWithOffset = (char)a;

	return (String) letterWithOffset;
}

String WavemanDecoder::GetNumberFromFourSymbolsCode(String code)
{
	byte matchingIndex = GetMatchingMappingIndex(code);

	if (matchingIndex < 0)
	{
		return "ERROR";
	}

	int numberWithOffset = 1 + matchingIndex;

	return (String(numberWithOffset));
}

byte WavemanDecoder::GetMatchingMappingIndex(String itemToMatch)
{
	for (size_t i = 0; i < 16; i++)
	{
		if (_mappings[i] == itemToMatch)
		{
			return i;
		}
	}

	return -1;
}

String WavemanDecoder::GetOnOffValue()
{
	if (_readValues[38] != _readValues[42] || _readValues[38] != _readValues[46])
	{
		return "ERROR";
	}

	return _readValues[38] ? "ON" : "OFF";
}