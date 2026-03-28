
/**
 * @file LinkedListCycle.cpp
 * @brief Detects if a singly linked list contains a cycle using Floyd's Tortoise and Hare algorithm.
 *
 * Uses two pointers moving at different speeds to determine if a cycle exists.
 */

/**
 * @class Solution
 * @brief Provides a method to check for cycles in a linked list.
 */

class Solution {
public:
    typedef struct Node{
        int data;
        struct Node *next;
    } ListNode;
    
    /**
     * @brief Determines if a linked list has a cycle.
     *
     * @param head Pointer to the head of the linked list.
     * @return true if a cycle exists, false otherwise.
     */
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
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