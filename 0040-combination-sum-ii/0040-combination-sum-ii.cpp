class Solution {
public:
    vector<vector<int>> res;
    void check(int index,vector<int>&candidates,vector<int>&ans,int k,int sum){
        if(sum==k){
            res.push_back(ans);
            return;
        }
        if(sum>k) return;
        for(int i=index;i<candidates.size();i++){
            if(i>index){if(candidates[i]==candidates[i-1]) continue;}
            ans.push_back(candidates[i]);
            check(i+1,candidates,ans,k,sum+candidates[i]);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>ans;
        check(0,candidates,ans,target,0);
        return res;
    }
};