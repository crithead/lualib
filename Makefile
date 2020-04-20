# Makefile to create and test a Lua 5.2/5.3 library.
# It creates a shared object with the requisite Lua import calls.
#
# The problem is that the library functions are not visible inside a Lua
# script, though the interpreter seems to load it.
#

CC = gcc
CFLAGS = -O2 -Wall -pedantic -std=c99

SOURCES := main.c

OBJECTS := $(SOURCES:.c=.o)

LIBSRC := dicebag.c
LIBSRC += ldicebag.c

LIBOBJ := $(LIBSRC:.c=.o)

# This is the shared object that is loaded by the Lua interpreter.
SHAREDOBJ = libdicebag.so

# This is the C test programs for dicebag.c
EXEC = ctest

#LIBINC := -I /usr/include/lua5.2
LIBINC := -I /usr/include/lua5.3

#LIBS = -ldicebag -llua5.2
LIBS = -ldicebag -llua5.3

all: $(EXEC) lualib

$(EXEC): $(OBJECTS) $(SHAREDOBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS) $(LIBS) -L.

$(SHAREDOBJ): $(LIBOBJ)
	$(CC) -shared -o $@ $(LIBOBJ) $(LIBINC)

dicebag.o : dicebag.c
	$(CC) -c $(CFLAGS) -fPIC $<

ldicebag.o : ldicebag.c
	$(CC) -c $(CFLAGS) -fPIC $< $(LIBINC)

# Create a symlink to the SO so Lua can reference it as just "dicebag"
.PHONY: lualib
lualib:
	ln -s $(SHAREDOBJ) dicebag.so

.PHONY: clean
clean:
	@rm -f *.o *.d *.so
	@rm -f $(EXEC)
	@rm -f $(SHAREDOBJ)

# Run the test programs
#
# Note: You may need to set "export LD_LIBRARY_PATH=$PWD" so the test program
# can load the library.
#
.PHONY: test
test:
	@echo "=== Running C library test"
	./$(EXEC)
	@echo "=== Running Lua library test"
	lua test.lua
	@echo "=== Rolling up some characters"
	lua rollchars.lua

