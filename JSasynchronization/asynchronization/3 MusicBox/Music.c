#include "Music.h"

sbit Voice = P1^0; 
byte MusicIndex = 0;
uint16 MusicPosition;
#define MusicCount 16
byte ShowDigit = true;

#include "MusicContent.h"


byte* code sound[] = {
	s0, s1, s2, s3, s4, s5, s6, s7, 
	s8, s9, s10,s11,s12,s13,s14,s15
};
char* code soundName[] = {
	sn0, sn1, sn2, sn3, 
	sn4, sn5, sn6, sn7, 
	sn8, sn9, sn10,sn11,
	sn12,sn13,sn14,sn15
};

byte time = 0, length;
void Sleep(uint16 yj);
void MusicAction();
void LedControl(byte height);

uint16 MusicTimerPeriod = 10000;
#define ResetMusicTimer() { \
	TH0 = (0xFFFF - MusicTimerPeriod) >> 8;	\
	TL0 = (0xFFFF - MusicTimerPeriod) & 0xFF;\
}

void StartMusicTimer()
{
	EA = 1;
	TMOD |= 0x01;
	ET0 = 1;
	TR0 = 1;
	ResetMusicTimer();	
}

void ChangeMusic(byte musicIndex)
{
	if (musicIndex < MusicCount)
	{
		MusicIndex = musicIndex;
		MusicPosition = 0;
	}
}

void MusicInterrupt() interrupt 1
{
	time++;
	ResetMusicTimer();
}

void MusicLoop()
{
	while (true)
	{
		MusicPosition = 0;
		MusicTimerPeriod = sound[MusicIndex][++MusicPosition];
		MusicTimerPeriod <<= 8;
		MusicTimerPeriod += sound[MusicIndex][++MusicPosition];
		SendString(soundName[MusicIndex]);
		MusicAction();
	}
}

void MusicAction()
{
	byte height;
	uint16 actualHeight;
	byte speed = sound[MusicIndex][++MusicPosition];
	while (true)
	{
		time = 0;
		if (MusicPosition == 0)
			return;
		height = sound[MusicIndex][++MusicPosition];
		length = sound[MusicIndex][++MusicPosition];
		if (height & length == 0xff)
		{
			speed = sound[MusicIndex][++MusicPosition];
			height = sound[MusicIndex][++MusicPosition];
			length = sound[MusicIndex][++MusicPosition];
		}
		LedControl(height);
		actualHeight = height * speed / 0x10;
		while (time != length)
		{
			if (height == 0)
				return;
			if (height != 0xff)
			{
				Voice = !Voice;
				Sleep(actualHeight);
			}
			else
			{
				Voice = 0;
				Sleep(actualHeight);
			}
		}
	}
}

void Sleep(uint16 yj)
{
	yj -= 11;
	KeyboardInterrupt();
	while (yj--);
}

void LedControl(byte height)
{
	byte target;
	if (height == 0xff)
		target = 0xff;
	else if (height >= 0x60)
		target = 0x81;
	else if (height >= 0x55)
		target = 0xc1;
	else if (height >= 0x4c)
		target = 0xe1;
	else if (height >= 0x48)
		target = 0xf1;
	else if (height >= 0x40)
		target = 0xf9;
	else if (height >= 0x38)
		target = 0xfd;
	else if (height >= 0x33)
		target = 0xff;
	else if (height >= 0x30)
		target = 0x7f;
	else if (height >= 0x2b)
		target = 0x3f;
	else if (height >= 0x26)
		target = 0x1f;
	else if (height >= 0x24)
		target = 0x0f;
	else if (height >= 0x20)
		target = 0x07;
	else if (height >= 0x1c)
		target = 0x03;
	else if (height >= 0x19)
		target = 0x01;
	else if (height >= 0x18)
		target = 0x81;
	else if (height >= 0x15)
		target = 0xc1;
	else if (height >= 0x13)
		target = 0xe1;
	else if (height >= 0x12)
		target = 0xf1;
	else if (height >= 0x10)
		target = 0xf9;
	else if (height >= 0x0e)
		target = 0xfd;
	else if (height >= 0x0d)			
		target = 0xff;
	P1 = P1 & 1;
	P1 |= target;
	//0x0d 1111 1111
	//0x0e 1111 1101
	//0x10 1111 1001
	//0x12 1111 0001
	//0x13 1110 0001
	//0x15 1100 0001
	//0x18 1000 0001
	//
	//0x19 0000 0001
	//0x1c 0000 0011
	//0x20 0000 0111
	//0x24 0000 1111
	//0x26 0001 1111
	//0x2b 0011 1111
	//0x30 0111 1111
	//
	//0x33 1111 1111
	//0x39 1111 1101
	//0x40 1111 1001
	//0x48 1111 0001
	//0x4c 1110 0001
	//0x55 1100 0001
	//0x60 1000 0001
}