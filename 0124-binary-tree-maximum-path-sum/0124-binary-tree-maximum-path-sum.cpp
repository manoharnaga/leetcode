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
        if(!root) return INT_MIN;
        
        int l = rec(root->left,ans);
        int r = rec(root->right,ans);
        
        ans = max(ans,root->val);
        
        if(l==INT_MIN && r==INT_MIN) return root->val;
        
        if(l!=INT_MIN)  ans = max({ans,l,l+root->val});
        if(r!=INT_MIN) ans = max({ans,r,r+root->val});
        
        if((l!=INT_MIN) && (r!=INT_MIN)) ans = max(ans,l+r+root->val);
        
        int ret = root->val;
        if(l!=INT_MIN) ret = max(ret,l+root->val);
        if(r!=INT_MIN) ret = max(ret,r+root->val);
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        rec(root,ans);
        return ans;
    }
};