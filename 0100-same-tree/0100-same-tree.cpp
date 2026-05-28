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
    int mini=1;
    void check(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) {
            mini=min(mini,1);
            return;
        }
        if(p==NULL || q==NULL) {
            mini=0;
            return;
        }
        if(p->val != q->val) {
            mini=min(mini,0);
            return;
        }
        check(p->left,q->left);
        check(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        check(p,q);
        return mini;
    }
};