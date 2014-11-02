/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 3, 2014
    Problem:    Swap Nodes in Pairs 
    Source:     https://oj.leetcode.com/problems/swap-nodes-in-pairs/
    
    Note:       
    Given a linked list, swap every two adjacent nodes and return its head.

    For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.

    Your algorithm should use only constant space. 
    You may not modify the values in the list, only nodes itself can be changed.

    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    Solution:   Nodes change.
                1.  odd nodes:  last node no change;
                2.  even nodes: change each pair
 */
                
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
            return head;
        
        ListNode *pre = head;
        ListNode *current = head;
        ListNode *post = current->next;

        if(post!=NULL){
            head = post;
            pre = current;
        }

        while(post!=NULL){
            pre->next = post;
            current->next = post->next;
            post->next = current;

            pre = current;
            current = current->next;
            if(current!=NULL){
                post = current->next;
            }
            else{
                post = NULL;
            }
        }

        return head;
    }
};