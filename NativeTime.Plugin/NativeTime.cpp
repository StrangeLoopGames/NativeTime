// RuntimeGraphicsInfo.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "NativeTime.h"

#include "IUnityInterface.h"
#include "IUnityGraphics.h"

static IUnityInterfaces* s_UnityInterfaces = nullptr;

// Unity plugin load event
extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
UnityPluginLoad(IUnityInterfaces * unityInterfaces)
{
    s_UnityInterfaces = unityInterfaces;
}

// Unity plugin unload event
extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
UnityPluginUnload()
{
}

