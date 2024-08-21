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
    TreeNode* rec(vector<int>& a,int low,int high){
        if(low>high) return nullptr;
        if(low==high){
            return new TreeNode(a[low]);
        }
        int mid = (low+high+1)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = rec(a,low,mid-1);
        root->right = rec(a,mid+1,high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
        int n = a.size();
        return rec(a,0,n-1);
    }
};