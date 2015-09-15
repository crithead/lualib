/*
 * Exercise the dicebag C library API.
 */
#include <stdio.h>
#include "dicebag.h"

int main( int argc, char **argv )
{
	int n;
	dicebag_init();

	n = dicebag_roll( 100 );
	printf( "roll( 100 ) -> %d\n", n );

	n = dicebag_range( 100, 200 );
	printf( "range( 100, 200 ) -> %d\n", n );

	n = dicebag_range( -200, -100 );
	printf( "range( -200, -100 ) -> %d\n", n );

	n = dicebag_dice( 10, 10 );
	printf( "dice( 10, 10 ) -> %d\n", n );

	n = dicebag_best( 10, 20, 10 );
	printf( "best( 10, 20, 10 ) -> %d\n", n );

	return 0;
}

