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
    pair<int,int> rec(TreeNode* root,int& ans){
        if(!root) return {0,1};

        int f = 1;
        if(root->left){
            TreeNode* l = root->left;
            int lval = l->val;
            while(l){
                lval = max(l->val,lval);
                l = l->right;
            }
            if(lval>=root->val) f=0;
        }

        if(root->right){
            TreeNode* r = root->right;
            int rval = r->val;
            while(r){
                rval = min(rval,r->val);
                r = r->left;
            }
            if(rval<=root->val) f=0;
        }
        
        pair<int,int> l = rec(root->left,ans);
        pair<int,int> r = rec(root->right,ans);
        
        
        if(!l.second || !r.second) return {0,0};

        int sum = root->val+l.first+r.first;
        if(f) ans = max(ans,sum);
        return {sum,f};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        rec(root,ans);
        return ans;
    }
};
