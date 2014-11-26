/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Merge Two Sorted Lists 
    Source:     https://oj.leetcode.com/problems/merge-two-sorted-lists/
    Note:

    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists.

    Definition for singly-linked list.
    
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };

    Solution:   Simulation
 */ 

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;

        ListNode *head;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }

        ListNode *p = head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1==NULL)
            p->next = l2;
        else
            p->next = l1;

        return head;
    }
};
