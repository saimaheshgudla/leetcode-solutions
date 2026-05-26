class Solution {
public:
    vector<vector<int>> res;

    void targett(vector<int>& candidates, vector<int>& ans, int i, int sum, int target) {
        if (sum == target) {
            res.push_back(ans);
            return;
        }
        if (i >= candidates.size()) return;

        for (int j = i; j < candidates.size(); j++) {
            if (sum + candidates[j] > target) break; 
            ans.push_back(candidates[j]);
            targett(candidates, ans, j, sum + candidates[j], target);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end()); 
        targett(candidates, ans, 0, 0, target);
        return res;
    }
};