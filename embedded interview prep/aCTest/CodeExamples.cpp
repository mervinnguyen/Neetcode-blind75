//What does the following code output and why?

void foo(void){
    unsigned int a = 6;
    int b = -20;

    (a+b > 6) ? puts("> 6") : puts("<=6");
}

//When you add unsigned int and a signed int, both types become unsigned int. C promotes both types to unsigned int for addition because unsigned dominates, therefore -20 is converted to a large unsigned int.
//This results into it outputting true, which is "> 6"

//13. Comment on the following code fragment

unsigned int zero = 0;
unsigned int compzero = 0xFFFF;     /*1's complement of zero*/

// 14. Embedded systems does dynamically allocate memory from the heap.
// What are the problems with dynamic memory allocation in embedded systems?
// Dynamic memory allocation (heap) can cause memory fragmentation (non-contiguous bytes) 

// What does the following code fragment output and why?
 char * ptr;
 if ((ptr = (char*)malloc(0) == NULL)){
    puts("Got a null pointer");
 } else {
    puts("Got a valid pointer");
 }

 //Approach:
 // -Currently declaring a ptr that points to unknown memory address that holds a char (1 byte)
 // -Dynaimcally allocate 0 bytes in memory type cased to a char and set it equal to the ptr. Check if its NULL
 // The corect answer is "it depends" since the result of malloc(0) is implementation defined.

 // 15. Typedef is frequently used in C to declare synonyms for pre-existing data types. 
 // It is also possible to use the preprocessor to do something similar. For instance, consider
 // the following code fragment:

 #define dPS struct s *


