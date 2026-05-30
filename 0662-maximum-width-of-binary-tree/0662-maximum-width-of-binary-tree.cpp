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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size = q.size();
            long long minleft = q.front().second;
            long long maxright = q.back().second;
            ans = max(ans, (int)(maxright - minleft + 1));
            for (int j = 0; j < size; j++) {
                TreeNode* curr = q.front().first;
                long long i = q.front().second;
                q.pop();
                if (curr->left) {
                    q.push({curr->left, 2 * i + 1});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * i + 2});
                }
            }
        }
        return ans;
    }
};