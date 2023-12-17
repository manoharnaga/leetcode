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
    void rec(TreeNode* root,int cnt,int& h,vector<int>& ans){
        if(!root) return;
        if(cnt>h){
            h++;
            ans.push_back(root->val);
        }
        rec(root->right,cnt+1,h,ans);
        rec(root->left,cnt+1,h,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        int h = 0;
        vector<int> ans;
        ans.push_back(root->val);
        rec(root,0,h,ans);
        return ans;
    }
};