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
    void find(vector<string>& res,string ch,TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            ch=ch+to_string(root->val);
            res.push_back(ch);
            return;
        }
         ch = ch + to_string(root->val) + "->";

        if(root->left != nullptr){
            find(res, ch, root->left);
        }

        if(root->right != nullptr){
            find(res, ch, root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string ch="";
        find(res,ch,root);
        return res;
    }
};