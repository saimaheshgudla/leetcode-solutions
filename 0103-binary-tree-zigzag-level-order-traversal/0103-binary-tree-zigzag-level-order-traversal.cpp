class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL) return {};

        queue<TreeNode*> q;
        q.push(root);

        int cnt = 0;

        vector<vector<int>> res;

        while(!q.empty()) {

            int size = q.size();

            vector<int> ans(size);

            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if(cnt == 0) {
                    ans[i] = curr->val;
                }
                else {
                    ans[size - 1 - i] = curr->val;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            cnt = 1 - cnt;

            res.push_back(ans);
        }

        return res;
    }
};