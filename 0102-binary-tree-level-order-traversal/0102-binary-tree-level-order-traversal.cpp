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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* it = q.front();
            q.pop();
            if(!it){
                ans.push_back(temp);
                temp.resize(0);
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                temp.push_back(it->val);
                if(it->left)    q.push(it->left);
                if(it->right)   q.push(it->right);
            }
        }
        return ans;
    }
};