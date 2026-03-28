/**
 * @file ImplementACircularBuffer.c
 * @brief Circular buffer (ring buffer) implementation for fixed-size integer storage
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

/**
 * @brief Circular buffer structure for integer data storage
 */
typedef struct circular_buffer{
    int buffer[BUFFER_SIZE];  /**< Fixed-size buffer array */
    int tail;                 /**< Read pointer */
    int head;                 /**< Write pointer */
    int count;                /**< Number of elements in buffer */
} circular_buffer;

/**
 * @brief Initialize a circular buffer to empty state
 * @param[out] cb Pointer to circular buffer structure
 * @return 0 on success
 */
int init_circular_buffer(circular_buffer *cb){
    cb->tail = 0;
    cb->head = 0;
    cb->count = 0;
    return 0;
}

/**
 * @brief Check if circular buffer is empty
 * @param[in] cb Pointer to circular buffer structure
 * @return true if buffer is empty, false otherwise
 */
bool is_empty(circular_buffer *cb){
    return (cb->count == 0);
}

/**
 * @brief Check if circular buffer is full
 * @param[in] cb Pointer to circular buffer structure
 * @return true if buffer is full, false otherwise
 */
bool is_full(circular_buffer *cb){
    return (cb->count == BUFFER_SIZE);
}

/**
 * @brief Push data into circular buffer
 * @param[in,out] cb Pointer to circular buffer structure
 * @param[in] data Integer data to push into buffer
 * @return 0 on success, -1 if buffer is full
 */
int push(circular_buffer *cb, int data){
    if (is_full(cb)){
        return -1;
    }
    cb->buffer[cb->head] = data;
    printf("The value being pushed into buffer is %d\n", cb->buffer[cb->head]);
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count += 1;
    return 0;
}

/**
 * @brief Pop data from circular buffer
 * @param[in,out] cb Pointer to circular buffer structure
 * @param[out] data Pointer to store popped data
 * @return 0 on success, -1 if buffer is empty
 */
int pop(circular_buffer *cb, int *data){
    if (is_empty(cb)){
        return -1;
    }
    *data = cb->buffer[cb->tail];
    printf("The value being popped from buffer is %d\n", *data);
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count -= 1;
    return 0;
}

/**
 * @brief Main function demonstrating circular buffer usage
 * @return 0 on success
 */
int main(void){
    circular_buffer *cb = malloc(sizeof(circular_buffer));
    int popped_value = 0;
    init_circular_buffer(cb);
    push(cb, 4);
    push(cb, 5);
    push(cb, 6);
    push(cb, 7);
    pop(cb, &popped_value);
    free(cb);
    return 0;
}