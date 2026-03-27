//Interrupts are an important part of embedded systems. Consequently, many compiler vendors offer an extension to standard C to support interrupts. 
//Typically, this new key word is __interrupt. tTeh following code uses __interrupt to define an ISR.
//Comment on the code

__interrupt double compute_area(double radius){
    double area = PI * radius * radius;
    printf("nArea = %f", area);
    return area;
}

// 1) ISRs cannot return a value
// 2) Can't pass an ISR as a parameter. Can only be called inside a function.
// 3) On compilers, floating point operations are not re-entrant. In other cases, one simply cannot do floating point in an ISR. 
// 4) Interrupts should be short and sweet.

