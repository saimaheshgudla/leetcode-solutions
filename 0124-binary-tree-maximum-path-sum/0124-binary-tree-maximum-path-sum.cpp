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
    int maxsum=INT_MIN;
    int totalheight(TreeNode* root){
        if(root==NULL) return 0;
        int ls=max(0,totalheight(root->left));
        int rs=max(0,totalheight(root->right));
        maxsum=max(maxsum,(root->val+ls+rs));
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        totalheight(root);
        return maxsum;
    }
};