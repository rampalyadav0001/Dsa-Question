https://leetcode.com/problems/rotate-list/description/
61. Rotate List
Medium
8.4K
1.4K
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;

        int count = 1;
        ListNode* temp = head;

        // Count the number of nodes in the linked list
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        // Connect the last node to the head, forming a circular linked list
        temp->next = head;

        // Calculate the actual number of positions to rotate
        k = k % count;

        // Find the new head position after rotation
        int newpos = count - k - 1;
        ListNode* newhead = head;

        // Move the newhead pointer to the correct position
        while (newpos--) {
            newhead = newhead->next;
        }

        // Update the head and break the circular linkage
        head = newhead->next;
        newhead->next = NULL;

        return head;
    }
};
