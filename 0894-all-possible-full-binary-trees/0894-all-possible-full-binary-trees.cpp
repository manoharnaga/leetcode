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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> v(n+1);
        if(n%2==0) return v[n];
        TreeNode* cur = new TreeNode(0);
        v[1].push_back(cur);
        for(int i=2;i<=n;i++){
            if(i%2==0)  continue;
            for(int j=2;(i-j)>=1;j+=2){
                int x1 = i-j;
                int x2 = i-x1-1;
                for(auto it1:v[x1]){
                    for(auto it2:v[x2]){
                        cur = new TreeNode(0);
                        cur->left = it1;
                        cur->right = it2;
                        v[i].push_back(cur);
                    }
                }
            }
        }
        return v[n];
    }
};