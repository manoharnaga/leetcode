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
    vector<int> ans,v;
    void rec(TreeNode* root,int h){
        if(!root) return;
        if(!v[h]){
            ans.push_back(root->val);
            v[h] = 1;
        }
        rec(root->right,h+1);
        rec(root->left,h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        ans.resize(0);
        v = vector<int>(101,0);
        rec(root,0);
        return ans;
    }
};