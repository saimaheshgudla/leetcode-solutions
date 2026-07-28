class Solution {
public:
    int fn(int i,vector<int>& vis,vector<int>nums){
        if(i==0) return nums[i];
        if(vis[i]!=-1) return vis[i];
        int pick=nums[i];
        if(i>1) pick=nums[i]+fn(i-2,vis,nums);
        int notpick=fn(i-1,vis,nums);
        return vis[i]=max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n,-1);
        return fn(n-1,vis,nums);
    }
};