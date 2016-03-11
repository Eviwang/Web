#include "Display.h"

// for public
uint16 DisplayNumber;

// 从右边到左边的数码管
#define DisplayBit1 0xEF
#define DisplayBit2 0xDF
#define DisplayBit3 0xBF
#define DisplayBit4 0x7F

static const byte code led_tab[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xA1,0x86,0x8E};

void DisplayOneDigitInterrupt()
{
	byte i;
	i = DisplayNumber % 10;
	P0 = (led_tab[i]);
	P3 = DisplayBit1;
}

//void DisplayInterrupt()
//{
//	static byte currentBit = 0;
//	byte i;
//	switch(currentBit)
//	{
//	case 0:
//		i = DisplayNumber % 10;
//		P0 = (led_tab[i]);
//		P3 = DisplayBit1;
//		break;
//	case 1:
//		i = DisplayNumber / 10 % 10;
//		P0 = (led_tab[i]);
//		P3 = DisplayBit2;
//		break;
//	case 2:
//		i = DisplayNumber / 100 % 10;
//		P0 = (led_tab[i]);
//		P3 = DisplayBit3;
//		break;
//	case 3:
//		i = DisplayNumber / 1000 % 10;
//		P0 = (led_tab[i]);
//		P3 = DisplayBit4;
//		break;
//	default:
//		// code never should go here
//		break;
//	}
//	currentBit += 1;
//	if (currentBit >= 4) currentBit = 0;
//}