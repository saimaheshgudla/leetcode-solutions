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
    int sum(TreeNode* root,int num){
        if(root->left==nullptr && root->right==nullptr){
            if(num==-1)return root->val;
            else return 0;
            
        }
        if(root->right==nullptr){
            return sum(root->left,-1);
        }
        if(root->left==nullptr){
            return sum(root->right,1);
        }
        int left= sum(root->left,-1);
        int right= sum(root->right,1);
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root,0);
    }
};