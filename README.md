# README

This is an example project that demonstrates how to create a Lua 5.2 extension
library.  It makes functions from the C library "dicebag" available in Lua.

## Build & Run

```
$ make
$ make test
$ lua probe.lua
```

For testing purposes set the loader path before trying to run the tests.  The
'ctest' executable needs it since it is built to load the 'so' library.

```
$ export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
```

The symlink is a hack to allow the loader to find the correct 'so' for 'ctest'
and to allow lua to load it by name without the lib prefix.

# To Do

* Figure out how to get a reference to the loaded library in the global
  namespace.  The functions are accessible in "_G.package.loaded.dicebag".


