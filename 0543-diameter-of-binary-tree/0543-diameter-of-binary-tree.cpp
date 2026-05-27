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
    int maxh= 0;
    int totalheight(TreeNode* root){
        if(root==NULL) return 0;
        int lh=totalheight(root->left);
        int rh=totalheight(root->right);
        maxh=max(maxh,(lh+rh));
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        totalheight(root);
        return maxh;
    }
};