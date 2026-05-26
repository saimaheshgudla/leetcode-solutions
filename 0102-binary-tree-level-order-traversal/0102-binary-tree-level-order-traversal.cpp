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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            int size=q.size();
            int i=0;
            while(i<size){
                TreeNode* it=q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                ans.push_back(it->val);
                i++;
            }
            res.push_back(ans);
        }
        return res;
    }
};