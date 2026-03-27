//Delete Node in a Linked List
//Given only accesss to a node in a singly linked list (not the tail), delete that node.

//ex1:
//Input: head = [4, 5, 1, 9], node = 5
//Output: [4, 1, 9]
//Explanation: Copy the next node's value into the given node and skip the next node.

//ex2:
//Input: head = [4, 5, 1, 9], node = 1
//Output: [4, 5, 9]

#include <iostream>

using namespace std;

//Approach:
//If we have *node pointing to 5, we can:
//  1) Set the current node's value to the next nodes value (result: [4, 1, 1, 9])
//  2) Create a temporary node that stores the next node 
//  3) Set the next node of the current node to skip the next node (result: node -> next ->next (9))
//  4) Delete the temporary node (result: [4, 1, 9])

typedef struct Node {
    int data;           
    struct Node *next;  
} ListNode;

void delete_node(ListNode *node){
    node -> data = node -> next -> data;    
    ListNode * temp = node -> next;         
    node -> next = node -> next -> next;    
    delete temp;                            
}

int main(void) {
    // Create linked list: 4 -> 5 -> 1 -> 9
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));

    n1->data = 4; 
    n1->next = n2;
    n2->data = 5; 
    n2->next = n3;
    n3->data = 1; 
    n3->next = n4;
    n4->data = 9; 
    n4->next = NULL;

    cout << "Original list: ";
    ListNode* curr = n1;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    delete_node(n2);

    // Print modified list
    cout << "After deleting node 5: ";
    curr = n1;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    free(n1);
    free(n2); 
    free(n3); 
    free(n4);

    return 0;
}