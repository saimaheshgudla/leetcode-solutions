class Solution {
public:
    vector<vector<int>> res;
    void targett(vector<int>& candidates,vector<int> ans,int i,int sum,int target){
        if(sum>target)return;
        if(target==sum){
            res.push_back(ans);
            return;
        }
        if(i>=candidates.size()) return;
        ans.push_back(candidates[i]);
        sum=sum+candidates[i];
        targett(candidates,ans,i,sum,target);
        sum=sum-candidates[i];
        ans.pop_back();
        targett(candidates,ans,i+1,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        targett(candidates,ans,0,0,target);
        return res;
    }
};