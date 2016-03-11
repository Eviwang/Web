#include "System.h"

void main()
{
	InitUart();
	StartMusicTimer();
	DisplayOneDigitInterrupt();
	MusicLoop();
}

void OnKeyUp(byte key)
{
	ChangeMusic(key);
	DisplayNumber = MusicIndex;
	DisplayOneDigitInterrupt();
}

void ByteRecieved(byte t)
{
	ChangeMusic(t);
	DisplayNumber = MusicIndex;
	DisplayOneDigitInterrupt();
}