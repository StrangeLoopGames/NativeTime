#include "pch.h"

#ifdef UNITY_OSX

#include "NativeTime.h"
#include "IUnityInterface.h"


extern "C" int64_t UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetTimestamp()
{
	return 0;
}


#endif