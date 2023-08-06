25. Reverse Nodes in k-Group
Hard
12K
603
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


question-Link::-->>https://leetcode.com/problems/reverse-nodes-in-k-group/description/

code:::-->
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* check=head;
        for(int i=0;i<k;i++){
           if(check==NULL)return head;
           check=check->next;
        }
        //reverse firsk k nodes;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL&&count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        // recursevely reverse the linked list;
        if(next!=NULL){
        head->next=reverseKGroup(next,k);

        }
        return prev;
    }
};