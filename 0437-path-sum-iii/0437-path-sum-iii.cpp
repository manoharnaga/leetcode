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
    typedef long long ll;
    ll ans;
    vector<ll> rec(TreeNode* root,ll targ){
        if(!root) return {};
        vector<ll> v,x,y;
        x = rec(root->left,targ);
        y = rec(root->right,targ);
        v.push_back(root->val);
        for(ll val: y){
            x.push_back(val);
        }
        for(ll val: x){
            v.push_back(val+root->val);
        }
        for(ll val: v){
            ans += (val==targ);
        }
        return v;
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        vector<ll> v = rec(root,(ll)targetSum);
        // for(int val: v){
        //     ans += (val==targetSum);
        // }
        return ans;
    }
};