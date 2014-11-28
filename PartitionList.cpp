/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 29, 2014
    Problem:    Partition List
    Source:     https://oj.leetcode.com/problems/partition-list/

    Given a linked list and a value x, 
    partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.

    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.

    Definition for singly-linked list.
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    Solution:   Use two pointer.
                1.  One pointer link the num < x;
                2.  One pointer link the num >=x;
                3.  Link these two pointer.
 */

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);

        ListNode *p = head;
        ListNode *p1 = h1;
        ListNode *p2 = h2;
        while(p!=NULL){
            if(p->val < x){
                p1->next = p;
                p1 = p1->next;
            }
            else{
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p2->next = NULL;
        p1->next = h2->next;

        head = h1->next;
        delete h1;
        delete h2;

        return head;
    }
};
