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
    void rec(TreeNode* root,vector<int>& v){
        if(!root) return;
        rec(root->left,v);
        v.push_back(root->val);
        rec(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        rec(root,v);
        int low = 0,high = v.size()-1;
        while(low<high){
            int sum = v[low]+v[high];
            if(sum==k) return true;
            else if(sum<k){
                low++;
            }
            else{
                high--;
            }
        }
        return false;
    }
};