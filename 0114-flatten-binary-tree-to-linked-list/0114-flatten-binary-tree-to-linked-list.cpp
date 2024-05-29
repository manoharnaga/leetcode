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
    TreeNode* prev;
    void rec(TreeNode* root){
        if(!root) return;
        if(prev){
           prev->right = root;
        }
        prev = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        rec(left);
        rec(right);
        root->left = NULL;
    }
    
    void flatten(TreeNode* root) {
        prev = nullptr;
        rec(root);
    }
};