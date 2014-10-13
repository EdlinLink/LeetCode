/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Oct. 14, 2014
    Problem:    Add Two Numbers 
    Source:     https://oj.leetcode.com/problems/add-two-numbers/
    Note:

    You are given two linked lists representing two non-negative numbers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

    Definition for singly-linked list.

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 
    Solution:   1. Adding value from two listnode pointers.
                2. Using one bit to record carry.

 */ 

#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool carry = false; 
        ListNode *head = NULL;
        ListNode *p_node = NULL;

        while(l1!=NULL || l2!=NULL || carry!=0){
            if(l1!=NULL && l2!=NULL){
                if(p_node==NULL){
                    p_node = new ListNode((l1->val + l2->val + carry) % 10);
                    head = p_node;
                }
                else{
                    p_node->next = new ListNode((l1->val + l2->val + carry) % 10);
                    p_node = p_node->next;
                }
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1!=NULL){
                p_node->next = new ListNode((l1->val + carry) % 10);
                p_node = p_node->next;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }
            else if(l2!=NULL){
                p_node->next = new ListNode((l2->val + carry) % 10);
                p_node = p_node->next;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }
            else{
                p_node->next = new ListNode(carry);
                p_node = p_node->next;
                carry = 0;
            }

        }
        return head;
    }
};
