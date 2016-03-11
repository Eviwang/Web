#ifndef __MUSIC_H_
#define __MUSIC_H_

#include "PreDefines.h"
#include "System.h"

void MusicInterrupt();
void StartMusicTimer();
void MusicLoop();
void ChangeMusic(byte musicIndex);

extern byte ShowDigit;
extern byte MusicIndex;
char* code SoundName[];

#endif