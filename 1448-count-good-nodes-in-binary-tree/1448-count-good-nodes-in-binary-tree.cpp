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
    int cnt;
    void rec(TreeNode* root,int maxsofar){
        if(!root) return;
        if(maxsofar<=root->val){
            cnt++;
            maxsofar = root->val;
        }
        rec(root->left,maxsofar);
        rec(root->right,maxsofar);
    }
    int goodNodes(TreeNode* root) {
        cnt = 0;
        rec(root,-1e5);
        return cnt;
    }
};