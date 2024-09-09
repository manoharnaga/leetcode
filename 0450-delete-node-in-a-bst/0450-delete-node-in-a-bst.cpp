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
    TreeNode* leftMost(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        // cout<<root->val<<"x\n";
        if(root->val==key){
            if(root->left && root->right){
                // cout<<"1\n";
                TreeNode* l = leftMost(root->right);
                root->val = l->val;
                root->right = deleteNode(root->right,l->val);
            }
            else if(root->left){
                // cout<<"2\n";
                return root->left;
            }
            else if(root->right){
                // cout<<"3\n";
                return root->right;
            }
            else{
                // cout<<"4\n";
                return nullptr;
            }
        }
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};