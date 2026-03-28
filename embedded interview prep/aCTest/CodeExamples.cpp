/**
 * @brief Demonstrates type promotion in C when adding unsigned and signed integers.
 *
 * When an unsigned int and a signed int are added, both are promoted to unsigned int.
 * This can lead to unexpected results if the signed int is negative.
 *
 * Output: "> 6" because -20 is converted to a large unsigned value.
 */
void foo(void){
    unsigned int a = 6;
    int b = -20;
    (a+b > 6) ? puts("> 6") : puts("<=6");
}

/**
 * @brief Example of bitwise complement.
 *
 * compzero is the 1's complement of zero (all bits set).
 */
unsigned int zero = 0;
unsigned int compzero = 0xFFFF;

/**
 * @brief Demonstrates malloc(0) behavior.
 *
 * The result of malloc(0) is implementation-defined; it may return NULL or a valid pointer.
 *
 * Output: "Got a null pointer" or "Got a valid pointer" depending on the implementation.
 */
char * ptr;
if ((ptr = (char*)malloc(0)) == NULL){
   puts("Got a null pointer");
} else {
   puts("Got a valid pointer");
}

/**
 * @brief Demonstrates a legal but confusing C construct: a+++b
 *
 * This is parsed as (a++) + b. The value of a is used, then incremented after the addition.
 *
 * Example:
 * int a = 5, b = 7, c;
 * c = a+++b; // c = 12, a becomes 6 after the statement
 */
int a = 5, b = 7, c;
c = a+++b;


