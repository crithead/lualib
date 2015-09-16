-- Generate some random graphs!
-- In this case a "graph" is a bunch of random points for vertices and
-- edge weights are distances.

-- Load the library object
require "dicebag"

info = {
	min_x = -100,
	max_x =  100,
	min_y = -100,
	max_y =  100,
	num_points = 40,
	min_distance = 5
}


function newpoint( info )
	p = {}
	p.x = dicebag.range( info.min_x, info.max_x )
	p.y = dicebag.range( info.min_y, info.max_y )
	return p
end

-- Calculate the distance between two points
function distance( a, b )
	return math.sqrt( (a.x - b.x)^2 + (a.y - b.y)^2 )
end

-- True if 'p' is within 'min' distance of an point in 'pts'
function tooclose( p, pts, min )
	--for q in pairs(pts) do
	for i = 1, #pts do
		if distance( p, pts[ i ] ) < min then
			return true
		end
	end
	return false
end

-- Generate a list of random points.  Each point is at least
-- 'info.min_distance' from any other point.
function generatepoints( info )
	pts = {} -- A List of Points
	while #pts < info.num_points do
		p = newpoint( info )
		if not tooclose( p, pts, info.min_distance )  then
			pts[ #pts + 1 ] = p
		end
	end
	return pts
end

-- Print the x,y pairs for each point in a list of points
function printpoints( pts )
	for i, p in pairs(pts) do
		print( p.x, p.y )
	end
end

-- Generate a bunch of points and print them
points = generatepoints( info )
printpoints( points )

-- End

