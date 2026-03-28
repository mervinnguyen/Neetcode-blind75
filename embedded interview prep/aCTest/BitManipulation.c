/**
 * @file BitManipulation.c
 * @brief Bit manipulation utilities for setting and clearing a specific bit
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdint.h>

#define BIT_3   (1 << 3)  /**< Bit mask for bit position 3 */

/**
 * @brief Sets bit 3 in a 32-bit value
 * @param[in] a Input value to modify
 * @return Modified value with bit 3 set
 * @note Other bits remain unmodified
 */
uint32_t set_bit(uint32_t a){
    a |= BIT_3; 
    return a;
}

/**
 * @brief Clears bit 3 in a 32-bit value
 * @param[in] a Input value to modify
 * @return Modified value with bit 3 cleared
 * @note Other bits remain unmodified
 */
uint32_t clear_bit(uint32_t a){
    a &= ~BIT_3;    
    return a;
}

/**
 * @brief Main function demonstrating bit manipulation operations
 * @return 0 on successful execution
 */
int main(void){
    uint32_t reg_val = 0;

    uint32_t set = set_bit(reg_val);
    printf("Current register is: %u \n", set);

    uint32_t clear = clear_bit(reg_val);
    printf("Current register after cleared is: %u", clear);

    return 0;
}