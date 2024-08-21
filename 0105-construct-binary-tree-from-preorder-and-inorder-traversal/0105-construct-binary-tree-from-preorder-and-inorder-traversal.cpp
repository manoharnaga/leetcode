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
    TreeNode* rec(vector<int>& po,vector<int>& in,int l1,int h1,int l2,int h2){
        
        
        // cout<<l1<<" "<<h1<<" "<<(h1-l1+1)<<"x\n";
        // cout<<l2<<" "<<h2<<" "<<(h2-l2+1)<<"y\n";
        
        if(l1>h1 || l2>h2) return nullptr;
        
        if(l1==h1) return new TreeNode(po[l1]);
        if(l2==h2) return new TreeNode(in[l2]);
        
        
        TreeNode* root = new TreeNode(po[l1]);
        int m2 = l2;
        while(in[m2]!=po[l1]) m2++;
        
        int m1 = l1+(m2-l2);
        
        root->left = rec(po,in,l1+1,m1,l2,m2-1);
        root->right = rec(po,in,m1+1,h1,m2+1,h2);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int low = 0,high = inorder.size()-1;
        return rec(preorder,inorder,0,high,0,high);
    }
};