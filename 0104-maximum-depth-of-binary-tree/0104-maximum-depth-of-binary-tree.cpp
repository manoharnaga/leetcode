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
    void rec(TreeNode* root,int cnt,int& ans){
        if(!root) return;
        ans = max(ans,cnt);
        rec(root->left,cnt+1,ans);
        rec(root->right,cnt+1,ans);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        int cnt = 1;
        rec(root,cnt,ans);
        return ans;
    }
};