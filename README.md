# NativeTime
Native time Unity package for burst compatibility

## Why is this needed?
Due to limitations in Burst, you cannot use `Stopwatch` or any of its function to calculate elapsed time. You also 
cannot use Unity's `Time.realtimeSinceStartup`.

Burst does however let you call native functions so this package includes a native plugin that returns the number of 
nanoseconds since startup, which is converted to ticks (100ns) and passed to `TimeSpan`.

## How to use

Create a new `ValueStopwatch` using `ValueStopwatch.StartNew()`
```cs

var sw = ValueStopwatch.StartNew();
DoThing();
var elapsed = sw.ElapsedTicks;

```

To reset, just reassign from `ValueStopwatch.StartNew()`

```cs

var sw = ValueStopwatch.StartNew();
DoThing1();
var elapsed1 = sw.ElapsedTicks;

sw = ValueStopwatch.StartNew();
DoThing2();
var elapsed2 = sw.ElapsedTicks;

```

You can also get the raw time in nanoseconds using `ValueStopwatch.GetTimestamp()` 