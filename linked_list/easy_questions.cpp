Middle of the Linked List
https://leetcode.com/problems/middle-of-the-linked-list/description/

code::-->>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
                slow=slow->next;
        }
        return slow;
    }
};


Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/description/

code::--->>
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* prev=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return prev;
    }
};

Detect Cycle in LinkedList
https://leetcode.com/problems/linked-list-cycle/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mp[temp]==true)return true;
            mp[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};

Detect cycle-2;
https://leetcode.com/problems/linked-list-cycle-ii/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <map>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       unordered_map<ListNode*,bool>mp;
       
       ListNode* temp=head;
       while(temp!=NULL&&temp->next!=NULL){
           if(mp[temp]==true){
               return temp;
           }
           mp[temp]=true;
      
           temp=temp->next;
       } 
       return NULL;
    }
};

