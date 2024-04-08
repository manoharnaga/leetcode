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
    void rec(TreeNode* root,int cnt,int f){
        if(!root) return;
        ans = max(ans,cnt);
        if(!f){
           rec(root->left,1,0);
           rec(root->right,cnt+1,1);
        }
        else{
           rec(root->left,cnt+1,0);
           rec(root->right,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        ans = 0;
        rec(root->left,1,0);
        rec(root->right,1,1);
        return ans;
    }
};