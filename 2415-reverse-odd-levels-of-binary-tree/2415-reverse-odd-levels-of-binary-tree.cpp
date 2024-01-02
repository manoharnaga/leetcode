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
    vector<int> v[15];
    void rec(TreeNode* root,int h){
        if(!root) return;
        if(h%2){
            v[h].push_back(root->val);
        }
        rec(root->left,h+1);
        rec(root->right,h+1);
    }
    void rec2(TreeNode* root,int h){
        if(!root) return;
        if(h%2){
            root->val = v[h].back();
            v[h].pop_back();
        }
        rec2(root->left,h+1);
        rec2(root->right,h+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        rec(root,0);
        rec2(root,0);
        return root;
    }
};