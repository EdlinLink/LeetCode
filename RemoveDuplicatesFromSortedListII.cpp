/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 28, 2014
    Problem:    Remove Duplicates from Sorted List II
    Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

    Given a sorted linked list, 
    delete all nodes that have duplicate numbers, 
    leaving only distinct numbers from the original list.

    For example,
    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3.

    Definition for singly-linked list.
    
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };

    Solution:   Skip all element that has the same value.
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

        if(head==NULL || head->next==NULL)  return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *p = newhead;

        while(p->next!=NULL){
            int element = p->next->val;
            int count = 0;
            ListNode *p2 = p->next;
            while(p2!=NULL && p2->val == element){
                count++;
                p2 = p2->next;
            }
            if(count > 1)
                p->next = p2;
            else
                p = p->next;
        }

        head = newhead->next;
        delete newhead;
        return head;
    }
    
};
