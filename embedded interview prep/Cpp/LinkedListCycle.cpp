/**
 * @file LinkedListCycle.cpp
 * @brief Detects if a singly linked list contains a cycle using Floyd's Tortoise and Hare algorithm
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

/**
 * @brief Provides a method to check for cycles in a linked list using Floyd's cycle detection algorithm
 */
class Solution {
public:
    /**
     * @brief Node structure for singly linked list
     */
    typedef struct Node{
        int data;           /**< Data stored in the node */
        struct Node *next;  /**< Pointer to the next node in the list */
    } ListNode;
    
    /**
     * @brief Determines if a linked list has a cycle using Floyd's Tortoise and Hare algorithm
     * 
     * Uses two pointers moving at different speeds (slow moves 1 step, fast moves 2 steps).
     * If a cycle exists, the fast pointer will eventually meet the slow pointer.
     * 
     * @param[in] head Pointer to the head of the linked list
     * @return true if a cycle exists, false otherwise
     * @note Time complexity: O(n), Space complexity: O(1)
     */
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *slow = head;  // Tortoise pointer - moves one step at a time
        ListNode *fast = head;  // Hare pointer - moves two steps at a time
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If pointers meet, cycle detected
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};