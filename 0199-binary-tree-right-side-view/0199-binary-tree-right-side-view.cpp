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
    void rec(TreeNode* root,int cnt,vector<int>& ans){
        if(!root) return;
        if(ans.size()<cnt){
            ans.push_back(root->val);
        }
        rec(root->right,cnt+1,ans);
        rec(root->left,cnt+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rec(root,1,ans);
        return ans;
    }
};