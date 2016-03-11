#include "SerialPort.h"

void CloseUart();
void UartInterrupt();

void SendString(char* string)
{
	do
	{
		SBUF = *string;
		while (!TI);
		TI = 0;
	} while (*string++ != '\0');
}

void InitUart()
{
	SCON = 0x50;
	TMOD |= 0x20;
	TH1 = TL1 = 0xfd;
	EA = 1;
	ET1 = 0;
	TR1 = 1;
	ES = 1;
}

static void UartInterrupt() interrupt 4
{
	EA = 0;
	if (RI)
	{	
		byte t = SBUF;
		RI = 0;
		ByteRecieved(t);
	}
	EA = 1;
}