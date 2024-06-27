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
    ListNode* deleteMiddle(ListNode* h) {
        
        if(!h || !h->next)return NULL;
        if(!h->next->next){
            h->next=NULL;
            return h;
        }
        /*
        10 20 30 40 50 60
              s      f            
        */ 
        ListNode*f=h,*s=h,*p=h;
        while(f && f->next){
            if(s!=h)p=p->next;
            f=f->next->next;
            s=s->next;
        }
        p->next=s->next;
        return h;
    }
};