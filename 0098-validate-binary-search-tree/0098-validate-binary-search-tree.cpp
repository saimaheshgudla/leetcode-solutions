class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }

    bool solve(TreeNode* root, long min, long max) {
        if(root == NULL) return true;

        if(root->left != NULL && root->left->val >= root->val) return false;
        if(root->right != NULL && root->right->val <= root->val) return false;

        if(root->val <= min || root->val >= max) return false;

        if(root->left && root->right){
            return solve(root->left, min, root->val) && solve(root->right, root->val, max);
        }
        if(root->left){
            return solve(root->left, min, root->val);
        }
        if(root->right){
            return solve(root->right, root->val, max);
        }
        return true;
    }
};