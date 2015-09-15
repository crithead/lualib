-- Test the ldicebag library for Lua

-- Load the library object
require "dicebag"

-- Print the library functions
print( "--- List library functions" )
for k, v in pairs(dicebag) do
	print(k, v)
end

-- Call functions
print( "--- Call library functions" )
n = dicebag.roll( 100 )
print( "dicebag.roll( 100 ) ->", n )

n = dicebag.range( 1000, 2000 )
print( "dicebag.range( 1000, 2000 ) ->", n )

n = dicebag.dice( 10, 6 )
print( "dicebag.dice( 10, 6 ) ->", n )

n = dicebag.dice( 10, 15, 6 )
print( "dicebag.best( 10, 15, 6 ) -> ", n )

print( "--- Done" )

