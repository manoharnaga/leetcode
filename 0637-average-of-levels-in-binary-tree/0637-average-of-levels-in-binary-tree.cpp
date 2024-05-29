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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double val = 0;
        int cnt = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it){
                val += it->val;cnt++;
            }
            if(!it){
                ans.push_back(val/cnt);
                val = 0;
                cnt = 0;
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
        }
        return ans;
    }
};