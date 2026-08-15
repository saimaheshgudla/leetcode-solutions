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
    void swapp(TreeNode* root){
        if(root==nullptr) return;
        swap(root->left,root->right);
        swapp(root->left);
        swapp(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        swapp(root);
        return root;
    }
};