/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int>v;
    TreeNode* recoverFromPreorder(string s) {
        int c=0,N=s.length();
        string n="";
        for(int i=0;i< N;i++) {
            if(s[i] != '-') {
                n+=string(1,s[i]);
                if(c)v.push_back(-c),c=0;
            }else {
                if(n != "") v.push_back(stoi(n)),n="";
                ++c;
            }
        }
        v.push_back(stoi(n));
        int pos=0;
        return go(v,0,pos);
        // 1, -1, 401, -2, 349, -3, 90, -2, 88 
        // 1,-1,2, -2 , 3, -3,4, -1,5, -2, 6, -3 , 7
    }

    TreeNode* go(vector<int>&v,int l,int &pos) {
        if(pos == v.size())return NULL;
        TreeNode*c = new TreeNode(v[pos++]);
        
        if(pos < v.size() && -v[pos] == l+1 ) {
            c->left = go(v,l+1,++pos);
        }
        
        if(pos < v.size() && -v[pos] == l+1 ) {
            c->right = go(v,l+1,++pos);
        }

        return c;
    }

};