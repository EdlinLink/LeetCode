/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Rotate List 
    Source:     https://oj.leetcode.com/problems/rotate-list/
    Note:

    Given a list, rotate the list to the right by k places, where k is non-negative.

    For example:
    Given 1->2->3->4->5->NULL and k = 2,
    return 4->5->1->2->3->NULL.

    Definition for singly-linked list.

        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };

    Solution:   1.  Make it circle
                2.  Rotate k %= size 
                3.  Right rotate k equal to left rotate size-k, equal to head right move size-k
                4.  Make the tail NULL
 */ 

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return head;

        int size = 0;
        ListNode *p = head;
        while(p != NULL){
            size++;
            if(p->next == NULL){
                if(size<2)
                    return head;
                p->next = head;
                break;
            }
            p = p->next;
        }

        k %= size;

        for(int i=0; i<size-k-1; i++)
            head = head->next;
        p = head;
        head = head->next;
        p->next = NULL;

        return head;
    }
};
