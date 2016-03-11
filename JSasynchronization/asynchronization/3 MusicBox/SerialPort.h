#ifndef __SERIALPORT_H_
#define __SERIALPORT_H_

#include "PreDefines.h"
void SendString(char* string);
void ByteRecieved(byte t);
void InitUart();

#endif