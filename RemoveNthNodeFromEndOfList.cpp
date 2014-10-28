/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 28, 2014
    Problem:    Remove Nth Node From End of List
    Source:     https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
    
    Note:       
    Given a linked list, remove the nth node from the end of list and return its head.
    For example,

        Given linked list: 1->2->3->4->5, and n = 2.
        After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note:
    Given n will always be valid.
    Try to do this in one pass.

    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    Solution:   Two pointers 
                1. Pointer A move n steps;
                2. Pointer B start after A move n steps.
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL)
            return NULL;


        ListNode *forerunner = head;
        ListNode *chaser = head;
        ListNode *tobeDel;

        for(int i=0; i<n; i++)
            forerunner = forerunner->next;

        // If forrunner==NULL, that means delete the head.
        if(forerunner==NULL){
            tobeDel = head;
            head = head->next;
            delete tobeDel;
            return head;
        }

        while(forerunner->next!=NULL){
            forerunner = forerunner->next;
            chaser = chaser->next;
        }

        tobeDel = chaser->next;
        chaser->next = chaser->next->next;
        delete tobeDel;
        tobeDel = NULL;
        
        return head;
    }
};