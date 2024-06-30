/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h) {
        
        Node*t=h,*p=h,*ans,*help=new Node(0);
        
        while(t){
            Node* nxt = t->next;
            t->next=new Node(t->val);
            t->next->next=nxt;
            t=nxt;
        }
        
        // copy random ptr :     
        t=p;        
        while(t){
            if(t->random)t->next->random = t->random->next;            
            t=t->next->next;
        }
        
        t=p;
        ans=help;
        while(t){
            // Update answers ptrs
            help->next = t->next;
            help = help->next;
            
            // Update original links
            t->next = t->next->next;
            t=t->next;
        }        
        return ans->next;
    }
};