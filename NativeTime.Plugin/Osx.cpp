#include "pch.h"

#ifdef UNITY_OSX

#include "NativeTime.h"
#include "IUnityInterface.h"


extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API Init()
{
}

extern "C" uint64_t UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetTimestampNs()
{
	return clock_gettime_nsec_np(CLOCK_UPTIME_RAW);
}


#endif