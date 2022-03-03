// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "PlatformBase.h"

#ifdef UNITY_WIN
#include <windows.h>
#include <profileapi.h>

#elif UNITY_OSX
#include <time.h>

#elif UNITY_LINUX
#define _POSIX_C_SOURCE 199309L
#include <time.h>

#else
#error "Unsupported platform"
#endif

#endif //PCH_H
