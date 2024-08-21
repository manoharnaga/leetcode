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
        if(low==high) return new TreeNode(a[low]);
        
        TreeNode* root = new TreeNode(a[low]);
        
        int mid = low+1;
        while(mid<=high && a[mid]<a[low]) mid++;
        
        root->left = rec(a,low+1,mid-1);
        root->right = rec(a,mid,high);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int low = 0,high = preorder.size()-1;
        return rec(preorder,low,high);
    }
};