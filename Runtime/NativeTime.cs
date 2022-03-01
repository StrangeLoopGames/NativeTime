using System;
using System.Runtime.InteropServices;

namespace StrangeLoopGames.NativeTime
{
    internal class NativeTimeInternal
    {
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN || UNITY_STANDALONE_OSX || UNITY_EDITOR_OSX || UNITY_STANDALONE_LINUX || UNITY_EDITOR_LINUX
        [DllImport("NativeTimeNative")]
        public static extern long GetTimestamp();
#else
        /// <summary> Fallback for unsupported platform </summary>
        [BurstCompatible]
        public static long GetTimestamp() { return 0; }
#endif
    }

    /// <summary>A burst compatible Stopwatch. Similar to <see cref="Stopwatch"/>.</summary>
    [BurstCompatible]
    public struct ValueStopwatch
    {
        long start;

        /// <summary> Returns the number of ticks since system startup. </summary>
        public static long GetTimestamp() => NativeTimeInternal.GetTimestamp();

        public TimeSpan ElapsedTicks()
        {
            long elapsed = GetTimestamp() - this.start;
            return new TimeSpan(elapsed);
        }

        public static ValueStopwatch StartNew()
        {
            return new ValueStopwatch { start = GetTimestamp() };
        }
    }
}
