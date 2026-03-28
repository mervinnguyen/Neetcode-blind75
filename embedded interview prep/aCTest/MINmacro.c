/**
 * @brief Standard MIN macro to return the smaller of two arguments.
 *
 * Always parenthesize macro arguments and the entire expression to avoid precedence bugs.
 */
#define MIN(A,B)    (((A) < (B)) ? (A) : (B))