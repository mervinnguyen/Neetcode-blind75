//reverse a linked list
// A -> B -> C -> D -> NULL
// D -> C -> B -> A -> NULL

//step 1: create struct for linked list
struct Node {
    int data;
    struct Node *next;
};

//reverse linked list function
struct Node *reverse_linked_list(struct Node *head){    //takes in head as the current node that we are currently processing
    //define 3 pointer s to 3 nodes that we will need to track
    struct Node *prev = NULL;   //assign previous node to NULL, since there is no node before A
    struct Node *curr = head;   //set the head to the current node
    struct Node *next = NULL;   //set next node to NULL as well

    while(curr != NULL){     //ensures that we havent reached the end of the list yet
        next = curr -> next;        //store the address of curr's next node into next
        curr -> next = prev;        //set the next node of current to prev, which is NULL
        prev = curr;                //move previous pointer to curr pointer
        curr = next;                //move next pointer to current pointer
    }
    return prev;                    //return previous
}
