/**
 * @file CodeExamples.cpp
 * @brief Collection of C/C++ code examples demonstrating various language features and behaviors
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

/**
 * @brief Demonstrates type promotion in C when adding unsigned and signed integers
 * 
 * When an unsigned int and a signed int are added, both are promoted to unsigned int.
 * This can lead to unexpected results if the signed int is negative.
 * 
 * @note Output: "> 6" because -20 is converted to a large unsigned value
 */
void foo(void){
    unsigned int a = 6;
    int b = -20;
    (a+b > 6) ? puts("> 6") : puts("<=6");
}

unsigned int zero = 0;              /**< Zero value for bitwise complement demonstration */
unsigned int compzero = 0xFFFF;     /**< 1's complement of zero (all bits set) */

/**
 * @brief Demonstrates malloc(0) behavior
 * 
 * The result of malloc(0) is implementation-defined; it may return NULL or a valid pointer.
 * 
 * @note Output: "Got a null pointer" or "Got a valid pointer" depending on the implementation
 */
char * ptr;
if ((ptr = (char*)malloc(0)) == NULL){
   puts("Got a null pointer");
} else {
   puts("Got a valid pointer");
}

int a = 5;  /**< First operand for operator precedence demonstration */
int b = 7;  /**< Second operand for operator precedence demonstration */
int c;      /**< Result variable for operator precedence demonstration */

/**
 * @brief Demonstrates a legal but confusing C construct: a+++b
 * 
 * This is parsed as (a++) + b. The value of a is used, then incremented after the addition.
 * 
 * @note Example: if a=5, b=7, then c=12 and a becomes 6 after the statement
 */
c = a+++b;