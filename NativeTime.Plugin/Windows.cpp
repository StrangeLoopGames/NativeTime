#include "pch.h"

#ifdef UNITY_WIN

#include "NativeTime.h"
#include "IUnityInterface.h"

static uint64_t s_frequency = 0;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Init()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	s_frequency = frequency.QuadPart;
}

extern "C" uint64_t UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetTimestampNs()
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	uint64_t elapsed = time.QuadPart;
	
	return elapsed * SecondsToNanoSeconds / s_frequency;
}

#endif