#include "pch.h"

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define BGM "bgm.wav"

SHOUND_API void PlayBGM()
{
	PlaySound(TEXT(BGM), 0, SND_ASYNC);
}