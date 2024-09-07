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
class BSTIterator {
public:
    vector<int> v;
    int n;
    int idx;
    void io(TreeNode* root){
        if(!root) return;
        
        io(root->left);
        v.push_back(root->val);
        io(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        io(root);
        idx = -1;
        n = v.size();
    }
    
    int next() {
        idx++;
        return v[idx];
    }
    
    bool hasNext() {
        return ((idx+1)<n);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */