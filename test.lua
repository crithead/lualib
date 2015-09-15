-- Test the ldicebag library for Lua

-- Load the library object
require "dicebag"

-- Print the global environment
for n in pairs(_G) do print(n) end

-- Try to call a dicebag function (FAILS)
n = dicebag.roll( 100 ) --> attempt to index global 'dicebag' (a nil value)
n = roll( 100 ) --> attempt to call global 'roll' (a nil value)
print ('roll( 100 )', n )

