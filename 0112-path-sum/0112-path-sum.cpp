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
    bool targett(TreeNode* root, int sum,int target){
        if(root==nullptr) return false;
        sum+=root->val;
        if(root->left==nullptr && root->right ==nullptr) return sum==target;
        return targett(root->left,sum,target) || targett(root->right,sum,target);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return targett(root,0,targetSum);
    }
};