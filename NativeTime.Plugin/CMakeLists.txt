include_directories(PluginAPI)

add_library(NativeTimeNative SHARED
        PluginAPI/IUnityEventQueue.h
        PluginAPI/IUnityGraphics.h
        PluginAPI/IUnityGraphicsD3D11.h
        PluginAPI/IUnityGraphicsD3D12.h
        PluginAPI/IUnityGraphicsMetal.h
        PluginAPI/IUnityGraphicsVulkan.h
        PluginAPI/IUnityInterface.h
        PluginAPI/IUnityProfilerCallbacks.h
        PluginAPI/IUnityRenderingExtensions.h
        PluginAPI/IUnityShaderCompilerAccess.h
        framework.h
        NativeTime.cpp
        NativeTime.h
        Windows.cpp
        Osx.cpp
)

if (APPLE)
    target_precompile_headers(NativeTimeNative PRIVATE $<$<COMPILE_LANGUAGE:OBJC>:pch.h>)
else()
    target_precompile_headers(NativeTimeNative PRIVATE pch.h)
endif()

if (APPLE)
    set(CMAKE_C_FLAGS "-x objective-c")
    add_compile_options("-dynamiclib")
elseif(UNIX)
    add_compile_definitions(UNITY_LINUX=1)
endif()

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -Wl,-undefined,dynamic_lookup")
endif()