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
    vector<int>nums;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            inorder(root->left);
        }
        nums.push_back(root->val);
        if(root->right){
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false; 
        inorder(root);
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==k) return true;
            else if(nums[l]+nums[r]<k) l++;
            else r--;
        }
        return false;
    }
};