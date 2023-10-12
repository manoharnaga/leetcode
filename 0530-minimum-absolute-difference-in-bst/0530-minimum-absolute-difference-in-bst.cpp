class Solution {
public:

    void helper(int &ans,TreeNode* root,int &mn)
    {
        if(!root) return;
        helper(ans,root->left,mn);
        ans=min(ans,abs(root->val-mn));
        mn=root->val;
        helper(ans,root->right,mn);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        int mn=INT_MAX;
        helper(ans,root,mn);
        return ans;
    }
};