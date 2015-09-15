/**
 * A library for generating random numbers simulating polyhedron dice used
 * in various board games, war games and role-playing games.
 */
#ifndef DICEBAG_H
#define DICEBAG_H

/**
 * Initialize the library.
 */
extern void dicebag_init( void );

/**
 * Roll an n-sided die.
 *
 * \param sides The max value in the random range.
 * \return A random integer between 1 and 'sides', inclusive.
 */
extern int dicebag_roll( int sides );

/**
 * Generate a random number within a range.
 *
 * \param a The start of the range.
 * \param b The end of the range.
 * \return A random integer between 'a' and 'b', inclusive.
 */
extern int dicebag_range( int a, int b );

/**
 * Sum a number of random rolls.
 *
 * \param number The number of dice to roll.
 * \param sides The max value of the random range for each number.
 * \return The sum of 'number' dice rolls.
 */
extern int dicebag_dice( int number, int sides );

/**
 * The sum of the best rolls from a set of a die rolls.
 *
 * \param best The number of rolls whose sum to return.
 * \param number The number of dice to roll.
 * \param sides The max value of the random range for each number.
 * \return The sum of the 'best' of 'number' dice rolls.
 */
extern int dicebag_best( int best, int number, int sides );

#endif // DICEBAG_H

