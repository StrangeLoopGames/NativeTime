#include "pch.h"

#ifdef UNITY_WIN

#include "NativeTime.h"
#include "IUnityInterface.h"

#include <windows.h>
#include <profileapi.h>

static LARGE_INTEGER s_frequency = LARGE_INTEGER();

extern "C" int64_t UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetTimestamp()
{
	if (s_frequency.QuadPart == 0)
	{
		QueryPerformanceFrequency(&s_frequency);
	}

	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	time.QuadPart *= 1000000;
	time.QuadPart /= s_frequency.QuadPart;
	return time.QuadPart;
}

#endif