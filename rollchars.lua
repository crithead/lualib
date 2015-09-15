-- Roll up some characters using best 3 of 4d6

-- Load the library object
require "dicebag"

function calcscore( t )
	score = 0
	for i = 1, #t do
		score = score + t[ i ] - 10
	end
	return score
end

-- Roll a bunch of dice
print( "--- Hoody-hoo! Let's roll up some characters!" )
for j = 1, 10 do
	m = {}
	for i = 1, 6 do
		-- m[#m + 1] = dicebag.best( 3, 4, 6 )
		m[#m + 1] = dicebag.dice( 3, 6 )
	end
	score = calcscore( m )
	s = string.format( "%2d\t%2d\t%2d\t%2d\t%2d\t%2d\t(%+3d)", 
			m[1], m[2], m[3], m[4], m[5], m[6], score )
	print( s )
end

