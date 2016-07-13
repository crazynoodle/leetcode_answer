//Remove Linked List Elements
/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5 
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        ListNode *ltr = head;//暂存指针，保存对比节点的前一个节点；
        ListNode *tra = head;//遍历指针
        bool HeadFlag = true;
        while(tra){
            if(tra->val == val){
                tra = tra->next;
                if(HeadFlag){
                    head = tra;
                    ltr = tra;
                }else{
                    ltr->next = tra;
                }
            }else{
                if(HeadFlag)
                    HeadFlag = false;
                ltr = tra;
                tra = tra->next;
            }
        }
        return head;
    }
};
