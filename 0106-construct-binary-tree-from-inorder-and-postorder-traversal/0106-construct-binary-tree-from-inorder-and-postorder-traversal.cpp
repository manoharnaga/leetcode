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

    TreeNode* rec(vector<int>& po,vector<int>& in,int l1,int h1,int l2,int h2,map<int,int>& mp){
        if(l1>h1 || l2>h2) return NULL;
        if(l1==h1) return new TreeNode(po[h1]);

        TreeNode* root = new TreeNode(po[h1]);
        int m2 = mp[po[h1]];
        int m1 = l1+m2-l2-1;

        root->left = rec(po,in,l1,m1,l2,m2-1,mp);
        root->right = rec(po,in,m1+1,h1-1,m2+1,h2,mp);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[inorder[i]] = i;
        return rec(postorder,inorder,0,n-1,0,n-1,mp);
    }
};