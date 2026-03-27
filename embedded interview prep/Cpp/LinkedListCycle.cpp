//Linked List Cycle
//Problem:
//Given the head of a linked list, determine if the linked list has a cycle in it.

class Solution{
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr){
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; 
            }
        }
        return false;
    }
};