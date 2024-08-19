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
    int widthOfBinaryTree(TreeNode* root){
    int maxWidth = 1; //stores maxWidth from levels

    queue<pair<TreeNode*, int>> q; //for BFS traversal; as {node, offset (from first node) of pos in binary tree at curr lvl}
    q.push({root, 1});
    q.push({NULL, 0});
    pair<TreeNode*, int> firstNode = q.front(); //stores first node of curr lvl

    while (q.size() > 0){
        pair<TreeNode*, int> temp = q.front();
        q.pop();

        if (temp.first == NULL){ //end of curr lvl
            if (q.size() > 0){
                maxWidth = max(q.back().second, maxWidth); //updating maxWidth using next lvl's width
                q.push({NULL, 0});
            }
        } else {
            if (temp.first->left != NULL || temp.first->right != NULL){ //a child exists
                if (q.back().first == NULL){ firstNode = temp; }//first node of level

                //pos of curr node relative to first node of curr lvl -> leads to its child's pos
                int pos = 2*(temp.second - firstNode.second) + 1 - ((firstNode.first->left != NULL) ? 0 : 1);

                if (temp.first->left != NULL){ q.push({temp.first->left, pos}); }
                if (temp.first->right != NULL){ q.push({temp.first->right, pos + 1}); }
            }
        }
    }

    return maxWidth;
}

};