/**
 * @file reverselinkedlist.c
 * @brief Reverse a singly linked list implementation
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * @brief Node structure for singly linked list
 */
struct Node {
    int data;           /**< Data stored in the node */
    struct Node *next;  /**< Pointer to the next node in the list */
};

/**
 * @brief Reverses a singly linked list in-place
 * 
 * Uses three-pointer technique to reverse the direction of all next pointers.
 * The algorithm maintains previous, current, and next pointers to safely
 * traverse and reverse the list without losing references.
 * 
 * @param[in] head Pointer to the head of the list to reverse
 * @return Pointer to the new head of the reversed list (previously the tail)
 */
struct Node *reverse_linked_list(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/**
 * @brief Main function demonstrating linked list reversal
 * 
 * Creates a simple 3-node linked list and reverses it.
 * 
 * @return Exit status code
 * @warning Memory allocated for nodes is not freed - potential memory leak
 */
int main(void) {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 1;
    second->data = 1;
    third->data = 1;

    head = reverse_linked_list(head);
    printf("%d -> ", head->data);
    return 0;
}