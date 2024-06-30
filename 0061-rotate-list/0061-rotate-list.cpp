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
    ListNode* rotateRight(ListNode* h, int k) {
        /*
             10 20 30 40 50 60 
             k=4,l=6;
             6 - (4%6)--> 2 
        */
        if(!h || !h->next || !k)return h;
        ListNode*t=h,*f=h,*s=h;
        int l=1;
        while(h->next)h=h->next,++l;
        if(!(k%l))return t;
        h->next =t;
        k = l - (k % l);
        while(k > 0)h=h->next,--k;
        t=h->next;
        h->next=NULL;
        return t;
    }
};