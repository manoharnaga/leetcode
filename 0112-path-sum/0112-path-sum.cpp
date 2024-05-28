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
    bool hasPathSum(TreeNode* root, int x) {
        if(!root) return false;
        x-=root->val;
        if(x==0 && !root->right && !root->left) return true;
        bool val = hasPathSum(root->right,x);
        if(val) return true;
        val = val || hasPathSum(root->left,x);
        return val;
    }
};