// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the NATIVETIME_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// NATIVETIME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <cstdint>
#include "IUnityInterface.h"

#ifdef NATIVETIME_EXPORTS
#define NATIVETIME_API __declspec(dllexport)
#else
#define NATIVETIME_API __declspec(dllimport)
#endif

extern "C" int64_t UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetTimestamp();
