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
        if(!root || !ans) return 0;
        
        int l = rec(root->left,ans);
        int r = rec(root->right,ans);
        
        if(abs(r-l)>1){
            ans = 0;
            return 0;
        }
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = 1;
        rec(root,ans);
        return ans;
    }
};