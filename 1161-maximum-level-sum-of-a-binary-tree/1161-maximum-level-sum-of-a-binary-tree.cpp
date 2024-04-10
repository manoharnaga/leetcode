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
    int v[1010];
    void rec(TreeNode* root,int cnt){
        if(!root) return;
        if(v[cnt]==-1000000){
            v[cnt] = 0;
        }
        v[cnt] += root->val;
        rec(root->left,cnt+1);
        rec(root->right,cnt+1);
    }
    int maxLevelSum(TreeNode* root) {
        for(int i=0;i<1010;i++) v[i]=-1e6;
        rec(root,1);
        int ind = 1;
        for(int i=1;i<1010;i++){
            if(v[i]>v[ind]){
                cout<<v[i]<<" "<<i<<"\n";
                ind = i;
            }
        }
        // for(int i=0;i<5;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<"\n";
        return ind;
    }
};