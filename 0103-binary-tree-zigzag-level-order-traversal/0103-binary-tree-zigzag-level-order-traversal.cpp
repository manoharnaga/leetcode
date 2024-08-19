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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        int f = 0;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur){
                temp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            else{
                if(f) reverse(temp.begin(),temp.end());
                f = !f;
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }   
        }
        return ans;
    }
};