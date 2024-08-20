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
    void rec(TreeNode* root,int row,int col,map<pair<int,int>,vector<int>>& mp){
        if(!root) return;
        mp[{col,row}].push_back(root->val);

        rec(root->left,row+1,col-1,mp);
        rec(root->right,row+1,col+1,mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> mp;
        rec(root,0,0,mp);
        vector<vector<int>> ans;
        vector<int> temp;
        auto it=mp.begin();
        int prevcol=it->first.first;
        for(;it!=mp.end();it++){
            pair<int,int> rc = it->first;
            vector<int> v = it->second;
            sort(v.begin(),v.end());
            if(prevcol==rc.first){
                temp.insert(temp.end(), v.begin(), v.end());
            }
            else{
                ans.push_back(temp);
                temp = v;
            }
            prevcol = rc.first;
        }
        if(!temp.empty()) ans.push_back(temp);
        return ans;
    }
};
