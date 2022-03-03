#include "pch.h"

#ifdef UNITY_LINUX

#include "NativeTime.h"
#include "IUnityInterface.h"

const int NsToTicks = 100;
const int SecToTicks = 10000000;
const int SecondsToNanoSeconds = 1000000000;

struct timespec resolution;

extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Init()
{
	clock_getres(CLOCK_MONOTONIC_RAW, &resolution);
}

extern "C" uint64_t UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetTimestampNs()
{
	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC_RAW, &time);
	return (static_cast<uint64_t>(time.tv_sec) * SecondsToNanoSeconds) + static_cast<uint64_t>(time.tv_nsec);
}


#endif