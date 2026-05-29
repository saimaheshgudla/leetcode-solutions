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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mpp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
                TreeNode* curr=q.front().first;
                pair<int,int>currcr=q.front().second;
                q.pop();
                int row=currcr.first;
                int col=currcr.second;
                mpp[col][row].insert(curr->val);
                if(curr->left) {
                    q.push({curr->left,{row+1,col-1}});
                }
                if(curr->right){
                    q.push({curr->right,{row+1,col+1}});
                }
        }
        vector<vector<int>> ans;
        for (auto& [col, rowMap] : mpp) {        
            vector<int> colNodes;
            for (auto& [row, values] : rowMap) { 
                for (int val : values) {          
                    colNodes.push_back(val);
                }
            }
            ans.push_back(colNodes);
        }
        return ans;
    }
};