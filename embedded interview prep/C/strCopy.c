/**
 * @file strCopy.c
 * @brief Implements a simple string copy function for null-terminated strings
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <stdio.h>

/**
 * @brief Copies a null-terminated string from source to destination
 * 
 * This function performs a character-by-character copy using pointer arithmetic.
 * The destination buffer must be large enough to accommodate the entire source
 * string plus the null terminator.
 * 
 * @param[in] s Pointer to the source string (null-terminated)
 * @param[out] d Pointer to the destination buffer (must be large enough)
 * 
 * @warning No bounds checking is performed - caller must ensure destination
 *          buffer is sufficiently sized to prevent buffer overflow
 */
void str_copy(char *s, char *d) {
    while (*s != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}

/**
 * @brief Main function demonstrating string copy functionality
 * 
 * @return 0 on successful execution
 */
int main(void) {
    char s[8] = "ABCDEFG";  /**< Source string buffer */
    char d[8];              /**< Destination buffer must be at least as large as source + null terminator */
    str_copy(s, d);
    printf("%s\n", d);
    return 0;
}