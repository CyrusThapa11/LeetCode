/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* h) {
        if(!h)return NULL;
        ListNode*c=h,*n=h,*p,*t=h;
        /*
            10 20 30 40 50
          p c  n            
        */
        p=NULL;
        while(c && n){            
            n = n->next;
            c->next = p;
            p = c;
            c = n;              
        }
        t=p;
        return t;
    }
};