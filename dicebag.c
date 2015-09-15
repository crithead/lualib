#include <stdlib.h>
#include <time.h>

#define DEBUG_ARRAY 0

static double RAND_MAX_AS_DOUBLE = (double)RAND_MAX;

/* Generate a number in [0, n) */
static int _roll( int n )
{
	int r = rand();
	if ( r == RAND_MAX )
		r--;
	double x = (double)(r) / RAND_MAX_AS_DOUBLE;
	return (int)( n * x );
}

/*
 * Initialize the library.
 */
void dicebag_init( void )
{
	srand( time( NULL ) );
}

/*
 * Roll an n-sided die.
 */
int dicebag_roll( int sides )
{
	int value = 0;
	if ( sides > 0 )
		value = _roll( sides ) + 1;
	return value;
}

/*
 * Generate a random number within a range.
 */
int dicebag_range( int a, int b )
{
	int value = 0;
	if ( a < b )
		value =  a + _roll( b - a + 1 );
	else if ( a > b )
		value =  b + _roll( a - b + 1 );
	else /* a == b */
		value = a;
	return value;
}

/*
 * Sum a number of random rolls.
 */
int dicebag_dice( int number, int sides )
{
	int value = 0;
	for ( int i = 0; i < number; i++ )
		value += dicebag_roll( sides );
	return value;
}


void _sort( int *array, int size )
{
	for ( int i = 0; i < size - 1; i++ ) {
		int k = i;
		for ( int j = i + 1; j < size; j++ ) {
			if ( array[ k ] < array[ j ] )
				k = j;
		}
		int t = array[ i ];
		array[ i ] = array[ k ];
		array[ k ] = t;
	}
}

#if DEBUG_ARRAY
#include <stdio.h>
static void _print( int *array, int size )
{
	for ( int i = 0; i < size; i++ )
		printf( "%4d", array[ i ] );
	puts("");
}
#endif // DEBUG_ARRAY

/*
 * The sum of the best rolls from a set of a die rolls.
 */
int dicebag_best( int best, int number, int sides )
{
	int value = 0;
	int *n = (int *)malloc( number * sizeof(int) );

	for ( int i = 0; i < number; i++ )
		n[ i ] = dicebag_roll( sides );

#if DEBUG_ARRAY
	_print( n, number );
	_sort( n, number );
	_print( n, number );
#else
	_sort( n, number );
#endif // DEBUG_ARRAY

	for ( int i = 0; i < best; i++ )
		value += n[ i ];

	free( n );
	return value;
}


