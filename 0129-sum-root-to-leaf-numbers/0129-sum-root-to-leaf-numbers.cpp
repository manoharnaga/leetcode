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
    void rec(TreeNode* root,int val){
        if(!root) return;
        if(val==0){
            val = root->val;
        }
        else{
            val *= 10;
            val += root->val;
        }
        if(!root->left && !root->right){
            ans += val;
            return;
        }
        rec(root->left,val);
        rec(root->right,val);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        rec(root,0);
        return ans;
    }
};