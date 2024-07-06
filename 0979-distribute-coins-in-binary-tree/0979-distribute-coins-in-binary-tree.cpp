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
    int rec(TreeNode* root,int& ans){
        if(!root) return 0;
        int l = rec(root->left,ans);
        int r = rec(root->right,ans);
        ans += (abs(l)+abs(r));
        return (root->val-1+l+r);
    }
    
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        rec(root,ans);
        return ans;
    }
};