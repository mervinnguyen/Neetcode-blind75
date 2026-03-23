//reverse a linked list 
//ex.
// A -> B -> C -> D -> NULL
// D -> C -> B -> A -> NULL
#include <stdio.h>      //printf and scanf
#include <stdlib.h>     //heap allocated memory (malloc)

//create our struct for linked list
struct Node {
    int data;
    struct Node *next;      //next node
};  //mental note: struct Node should only contain data and pointer to next node

struct Node *reverse_linked_list(struct Node *head){      //take head as the current node being traversed
    //start from A as the head 
    struct Node *prev = NULL;
    struct Node *curr = head;   //set the input head node pointer to the current being processed
    struct Node *next = NULL;   //set next node as empty

    while (curr != NULL){
        next = curr->next;      //store the next node of current and save into next
        curr->next = prev;      //reverse the pointer
        prev = curr;            //move previous forward
        curr = next;            //move curr forward
    }
    return prev;
}

int main(void){
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    
    head->data = 1;
    second->data = 1;
    third -> data = 1;


    head = reverse_linked_list(head);

    printf("%d -> ", head->data);

    return 0;
}