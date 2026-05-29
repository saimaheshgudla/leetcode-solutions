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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return{};
        map<int,int>mpp;
        queue<pair<TreeNode*,int>>q;
        vector<int>res;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int row=q.front().second;
            q.pop();
            if(mpp.find(row)==mpp.end()){
                mpp[row]=curr->val;
            }
            if(curr->right){
                q.push({curr->right,row+1});
            }
            if(curr->left){
                q.push({curr->left,row+1});
            }
        }
        for(auto it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};