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
    // void inorder(TreeNode* root,vector<int>& v){
    //     if(!root) return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* rightmost = root->left;
                int f = 0;
                while(rightmost->right){
                    if(rightmost && rightmost->right==root){
                        rightmost->right = nullptr;
                        ans.push_back(root->val);
                        f=1;
                        break;
                    }
                    rightmost = rightmost->right;
                }
                if(!f){
                    rightmost->right = root;
                    root = root->left;
                } 
                else{
                    root = root->right;
                }
            }
        }
        return ans;
    }
};