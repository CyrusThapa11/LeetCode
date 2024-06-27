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
    ListNode* middleNode(ListNode* h) {
        if(!h->next)return h;
        ListNode*f = h->next->next,*s=h;
        while(f && f->next){
            f = f->next->next;
            s=s->next;                        
        }
        
        return (s->next);
    }
};