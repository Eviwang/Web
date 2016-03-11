#include "PreDefines.h"
#include "Keyboard.h"

byte KeyScan();

static byte KeyScan()
{
	// const KeyNone = 0xFF
	byte key = KeyNone;
	P2 = 0xf0;
	if((P2 & 0xf0) == 0xf0)
	{
		// Ã»ÓÐ°´¼ü
		key=KeyNone;
	}
	else
	{
		byte i;
		P2 = 0xf7;
		for(i = 0; i < 4; i++)
		{
			switch (P2 & 0xf0)
			{
			case 0xe0:
				key = i * 4 + 0;
				break;
		    case 0xd0:
				key = i * 4 + 1;
				break;
		    case 0xb0:
				key = i * 4 + 2;
				break;
			case 0x70:
				key = i * 4 + 3;
				break;
		    }
			P2=(P2 >> 1) | 0xf0;
			if (key < KeyNone)  break;
		}
    }
   return key;
}

void KeyboardInterrupt()
{
	static byte orgKey = KeyNone;
	byte key = KeyScan();
	if (key == KeyNone && orgKey != KeyNone)
		OnKeyUp(orgKey);
	orgKey = key;
}