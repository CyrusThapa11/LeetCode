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
class FindElements {
public:
    TreeNode* r;
    TreeNode* re(TreeNode* a,int v){
        if(!a)return NULL;
        TreeNode* r = new TreeNode(v);
        r->left=re(a->left,2*v + 1);
        r->right=re(a->right,2*v + 2);

        return r;
    }
    FindElements(TreeNode* a) {
        r = re(a,0);
    }
    bool ok(int v, TreeNode* a) {
        if(!a || a->val > v)return 0;
        if(a->val==v)return 1;
        
        return  ok(v,a->right) || ok(v,a->left);
    }
    bool find(int t) {
        return ok(t,r);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */