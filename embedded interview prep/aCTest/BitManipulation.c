//Bit Manipulation
//Given an integer variable a, write two code fragments.
//The first should set bit 3 of a.
//The second should clear bit 3 of a. 
//In both cases, the remaining bits should be unmodified.

#include <stdio.h>
#include <stdint.h>     //enable data types uint32_t, uint16_t, etc.

//define macro to set/clear bit 3
#define BIT_3   (1 << 3)        //shift to the third bit 

uint32_t set_bit(uint32_t a){
    a |= BIT_3;     //set bit 3 to 1
    return a;
}
uint32_t clear_bit(uint32_t a){
    a &= ~BIT_3;        //clear bit 3
    return a;
}
int main(void){
    //testing 
    uint32_t reg_val = 0;   //set register value to 0 for local testing

    uint32_t set = set_bit(reg_val);
    printf("Current register is: %u \n", set);

    uint32_t clear = clear_bit(reg_val);
    printf("Current register after cleared is: %u: ", clear);

    return 0;
}