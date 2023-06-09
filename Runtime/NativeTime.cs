using System;
using System.Runtime.InteropServices;
using Unity.Collections;

namespace StrangeLoopGames.NativeTime
{
    internal class NativeTimeInternal
    {
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN //|| UNITY_STANDALONE_OSX || UNITY_EDITOR_OSX || UNITY_STANDALONE_LINUX || UNITY_EDITOR_LINUX
        [DllImport("NativeTimeNative")]
        public static extern ulong GetTimestampNs();
#else
        /// <summary> Fallback for unsupported platform </summary>
        [GenerateTestsForBurstCompatibility]
        public static ulong GetTimestampNs() { return 0; }
#endif
    }

    /// <summary>A burst compatible Stopwatch. Similar to <see cref="Stopwatch"/>.</summary>
    [GenerateTestsForBurstCompatibility]
    public struct ValueStopwatch
    {
        public const ulong TicksToNanoseconds = 100;
        ulong start;

        /// <summary> Returns the number of nanoseconds since system startup. </summary>
        public static ulong GetTimestamp() => NativeTimeInternal.GetTimestampNs();

        public TimeSpan ElapsedTicks
        {
            get
            {
                ulong elapsed = GetTimestamp() - this.start;
                return new TimeSpan((long)(elapsed / TicksToNanoseconds));
            }
        }

        public static ValueStopwatch StartNew()
        {
            return new ValueStopwatch { start = GetTimestamp() };
        }
    }
}
