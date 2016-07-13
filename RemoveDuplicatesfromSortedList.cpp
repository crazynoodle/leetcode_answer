//Remove Duplicates from Sorted List
/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode * p = head;
        ListNode * q = p->next;
        while(p && q){
            if(q->val == p->val){
                //q->next = p->next;
                p->next = q->next;
                q = q->next;
            }else{
                p = q;
                q = q->next;
            }
        }
        
        return head;
    }
};
