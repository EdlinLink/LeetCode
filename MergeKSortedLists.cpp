/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 2, 2014
    Problem:    Merge k Sorted Lists
    Source:     https://oj.leetcode.com/problems/merge-k-sorted-lists/
    
    Note:       
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    Solution:   Normal Merge Sort Operation.                      
                But it will change the ListNode* in vector.
 */

class Solution {
public:
    ListNode *head;
    ListNode *p;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        return mergesort(lists, 0, lists.size()-1);
    }

    ListNode *mergesort(vector<ListNode *> &lists, int start, int end){
        int mid = (start+end)/2;
        ListNode *a = NULL;
        ListNode *b = NULL;

        if(start == mid)
            a = lists[start];
        else if(start < mid)
            a = mergesort(lists, start, mid);
    
        if(mid+1 == end)
            b = lists[end];
        else if(mid+1 < end)
            b = mergesort(lists, mid+1, end);

        return Merge(a, b);
    }
    
    ListNode *Merge(ListNode *a, ListNode *b){
        head = NULL;
        p = NULL;

        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                addNode(a);
                a = a->next;
            }
            else{
                addNode(b);
                b = b->next;
            }
        }

        if(a!=NULL )    addNode(a);
        if(b!=NULL )    addNode(b);

        return head;
    }

    void addNode(ListNode *pointer){
        if(p==NULL){
            p = pointer;
            head = p;
        }
        else{
            p->next = pointer;
            p = p->next;
        }
    }

};
