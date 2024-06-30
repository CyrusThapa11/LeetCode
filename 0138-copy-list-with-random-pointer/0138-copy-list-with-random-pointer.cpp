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
        unordered_map<Node*,Node*>mp;
        Node*t=h,*p=h;
        while(h){
            Node*c=NULL;
            if(mp.find(h)==mp.end()){
                c=new Node(h->val);
                mp[h]=c;
            }
            
            c = mp[h];
            if(mp.find(h->next)==mp.end()){
                Node*t=h->next ? new Node(h->next->val):NULL;
                mp[h->next] = t;
            }
            
            c->next=mp[h->next];
            if(mp.find(h->random)==mp.end()){
                Node*t=h->random ? new Node(h->random->val):NULL;
                mp[h->random] = t;
            }            
            c->random=mp[h->random];
            
            h=h->next;
        }
        return mp[p];
    }
};