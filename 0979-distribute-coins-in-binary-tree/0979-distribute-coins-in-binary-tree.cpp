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
    int ans;
    int rec(TreeNode* root){
        if(!root) return 0;
        int l = rec(root->right);
        int r = rec(root->left);
        ans += abs(l)+abs(r);
        return root->val+l+r-1;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        rec(root);
        return ans;
    }
};