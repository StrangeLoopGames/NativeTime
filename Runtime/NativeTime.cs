using System;
using System.Runtime.InteropServices;

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN || UNITY_STANDALONE_OSX || UNITY_EDITOR_OSX || UNITY_STANDALONE_LINUX || UNITY_EDITOR_LINUX
internal class NativeTimeInternal
{
    [DllImport("NativeTimeNative")]
    public static extern long GetTimestamp();
}
#else
internal class NativeTimeInternal
{
    public static long GetTimestamp() { return 0; }
}
#endif

public class NativeTime
{
    /// <summary> Returns the number of microseconds since system startup. </summary>
    public static long GetTimestamp() => NativeTimeInternal.GetTimestamp();
}