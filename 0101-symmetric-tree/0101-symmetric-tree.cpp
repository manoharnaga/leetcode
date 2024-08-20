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
    int rec(TreeNode* l,TreeNode* r){
        if(!l && !r) return 1;
        if(!l || !r) return 0;
        
        if(l->val!=r->val) return 0;
        
        int f1 = rec(l->left,r->right);
        int f2 = rec(l->right,r->left);
        return f1 && f2;
    }
    bool isSymmetric(TreeNode* root) {
        return rec(root->left,root->right);
    }
};