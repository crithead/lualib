-- Probe Lua for the "dicebag" library

-- Load the library object
require "dicebag"

-- Print the list of loaded packages
print( "--- Loaded packages" )
for v in pairs(_G.package.loaded) do print(v) end

print( "--- Library objects" )
for k, v in pairs(_G.package.loaded.dicebag) do print(k, v) end

-- Put a synbol in the global namespace that references the loaded
-- dicebag package.
dicebag = _G.package.loaded.dicebag

print( "--- Library functions" )

-- Call functions
n = dicebag.roll( 100 )
print( "dicebag.roll( 100 ) ->", n )

n = dicebag.range( 1000, 2000 )
print( "dicebag.range( 1000, 2000 ) ->", n )

n = dicebag.dice( 10, 6 )
print( "dicebag.dice( 10, 6 ) ->", n )

-- Roll a bunch of dice
print( "dicebag.best( 3, 4, 6 )" )
for j = 1, 10 do
	m = {}
	for i = 1, 6 do
		m[#m + 1] = dicebag.best( 3, 4, 6 )
	end
	s = string.format( "%d\t%d\t%d\t%d\t%d\t%d", m[1], m[2], m[3], m[4], m[5], m[6] )
	print( s )
end

