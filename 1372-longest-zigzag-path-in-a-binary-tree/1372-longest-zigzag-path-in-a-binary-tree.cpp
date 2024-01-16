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
    int ans = 0;
    void rec(TreeNode* root,int cnt,int f){
        if(!root){
            ans = max(ans,cnt-1);
            return;
        }
        if(f){
            rec(root->left,cnt+1,!f);
            rec(root->right, 1, 1);
        }
        else{
            rec(root->right,cnt+1,!f);
            rec(root->left, 1, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        rec(root->left,1,0);
        rec(root->right,1,1);
        return ans;
    }
};