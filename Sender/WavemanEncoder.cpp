#include "WavemanEncoder.h"

String _mappings [] = { "0000", "X000", "0X00", "XX00", "00X0", "X0X0", "0XX0", "XXX0", "000X", "X00X", "0X0X", "XX0X", "00XX", "X0XX", "0XXX", "XXXX" };
bool *_encodedValues;

WavemanEncoder::WavemanEncoder()
{

}

void WavemanEncoder::Encode(bool values[], char letter, byte number, bool isOn)
{
	_encodedValues = values;
	EncodeLetter(letter);
	EncodeNumber(number);
	EncodeOnOf(isOn);
}

void WavemanEncoder::EncodeLetter(char letter)
{
	int a = (int)'A';
	int i = (int) letter;
	int offset = i - a;

	SetValuesFromOffsetAndValuesArrayStartingIndex(offset, 0);
}

void WavemanEncoder::EncodeNumber(byte number)
{
	SetValuesFromOffsetAndValuesArrayStartingIndex(number - 1, 4);
}

void WavemanEncoder::SetValuesFromOffsetAndValuesArrayStartingIndex(byte mappingsOfset, byte valuesStartingIndex)
{
	String mappingItem = _mappings[mappingsOfset];

	char codeChars[6];
	mappingItem.toCharArray(codeChars, 6, 0);

	for (size_t i = 0; i < 4; i++)
	{
		char indexCharacter = codeChars[i];
		_encodedValues[valuesStartingIndex + i] = indexCharacter == 'X';
	}
}

void WavemanEncoder::EncodeOnOf(bool isOn)
{
	_encodedValues[8] = false;
	_encodedValues[9] = isOn;
	_encodedValues[10] = isOn;
	_encodedValues[11] = isOn;
}