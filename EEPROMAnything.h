/*
	Name:		EEPROMAnything.h
	Created:	2017.12.16
	Author:		pawelk
*/

#include <EEPROM.h>
#include <Arduino.h>  // for type definitions

/** Zapisanie struktury do pamieci nieulotnej. \p pe cos tam
	\1111111 11111111111111 \p 11111111111111
	\22222 2222 2222

	\ 33333333333 333333
	4444444444444444 4.
*/
template <class T> int eepromWriteStruct(int address, const T& value)
{
	const byte* p = (const byte*)(const void*)&value;
	unsigned int i;
	for (i = 0; i < sizeof(value); i++)
		EEPROM.write(address++, *p++);
	return i;
}

template <class T> int eepromReadStruct(int address, T& value)
{
	byte* p = (byte*)(void*)&value;
	unsigned int i;
	for (i = 0; i < sizeof(value); i++)
		*p++ = EEPROM.read(address++);
	return i;
}