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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return NULL;
        
        ListNode *q = NULL;
        ListNode *head = NULL;
        ListNode *p = NULL;
        head = q;
        ListNode *left = l1;
        ListNode *right = l2;
        int overflow = 0;
        bool Ishead = true;
        while(left !=NULL && right != NULL){
            p = new ListNode(0);
            int tem = left->val + right->val + overflow;
            if(tem/10 == 1)
                overflow = 1;
            else overflow = 0;
            p->val = tem%10;
            p->next = NULL;
            if(Ishead){
                head = p;
                q = p;
                Ishead = false;
            }else{
                q->next = p;
                q = p; 
            }
           
            left = left->next;
            right = right->next;
        }
        // if(overflow || left->)
        //     q->next = new ListNode(1);
        while(left!= NULL){
            p = new ListNode(0);
            int tem = left->val + overflow;
            if(tem/10 == 1)
                overflow = 1;
            else overflow = 0;
            p->val = tem%10;
            q->next = p;
            q = p;
            left = left->next;
        }
        while(right != NULL){
            p = new ListNode(0);
            int tem = right->val + overflow;
            if(tem/10 == 1)
                overflow = 1;
            else overflow = 0;
            p->val = tem%10;
            q->next = p;
            q = p;
            right = right->next;
        }
        if(overflow)
            q->next = new ListNode(1);
        return head;
    }
};
