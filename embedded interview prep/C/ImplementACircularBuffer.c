//implement a circular buffer/ring buffer
#include <stdio.h>      //for printf and scanf
#include <stdlib.h>     //for memory allocation
#include <stdbool.h>    //for boolean true or false

//define macro for size of buffer
#define BUFFER_SIZE     8

//define circular buffer struct
typedef struct circular_buffer{
    int buffer[BUFFER_SIZE];        //buffer size
    int tail;                       //read pointer
    int head;                       //write pointer
    int count;                      //counter for number of data inside of the buffer
}circular_buffer;

int init_circular_buffer(circular_buffer *cb){
    cb -> tail = 0;     //initialize tail to 0
    cb -> head = 0;     //initialize head to 0
    cb -> count = 0;    //initalize current count to 0, since empty
    return 0;
}
bool is_empty(circular_buffer *cb){
    return (cb -> count == 0);
}
bool is_full(circular_buffer *cb){
    return (cb -> count == BUFFER_SIZE);
}
int push(circular_buffer *cb, int data){
    if (is_full(cb)){
        return -1;      //if the circular buffer is full, throw an error exception
    }
    cb -> buffer[cb -> head] = data;  //set the current head position to value of data
    printf("The value being pushed into buffer is %d\n", cb -> buffer[cb -> head]);     //print value 
    cb -> head = (cb->head + 1) % BUFFER_SIZE;         //increment head value and reset back to 0 to avoid buffer overflow
    cb -> count += 1;   //increment count

    return 0;
}
int pop(circular_buffer *cb, int *data){
    if( is_empty(cb)){
        return -1;      //if circular buffer is empty, throw an error exception
    }
    *data = cb -> buffer[cb -> tail];     //take the value of tail stored in the buffer and set it to address of data
    printf("The value being popped from buffer is %d\n", *data);      //print out value that is being popped from buffer  
    cb -> tail = (cb -> tail + 1) % BUFFER_SIZE;        //increment position of tail
    cb -> count -= 1;       //decrement count since we pop value from buffer

    return 0;
}

int main(void){
    circular_buffer *cb = malloc(sizeof(circular_buffer));  //allocate memory on the heap
    int popped_value = 0;

    init_circular_buffer(cb);
    push(cb, 4);    //push integer 4 into circular buffer
    push(cb, 5);    //push integer 5 into circular buffer
    push(cb, 6);    //push integer 6 into circular buffer
    push(cb, 7);    //push integer 7 into circular buffer
    pop(cb, &popped_value);

    free(cb);       //free memory
    return 0;
}