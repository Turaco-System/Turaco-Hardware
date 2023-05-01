# SoftwareTODO

This is just an informal list of things we need to build to get Turaco up and running.  Please feel free to add to it.  Items are in no specific order *yet*.

1. Proper stub methods so stdio support for stdin, stdout works:
  - \_Stub\_write()
  - \_Stub\_read()
2. VT100/ANSI emulation baked into text mode.
  i.e. need a CHAROUT function that respects ANSI escape sequences.<br>
  [Here](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797) is a list of ANSI escape codes.
3. Full suite of default interrupt handlers baked into each program as part of the core library
4. Core system library with ready-made functions for talking to the VERA and filesystem


