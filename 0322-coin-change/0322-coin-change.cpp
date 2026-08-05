class Solution {
public:
    int find(int i,int sum,vector<int>& arr ,vector<vector<int>>& vis){
        if(i==0){
            if(sum % arr[i]==0) return sum/arr[i];
            return 1e9;
        }
        if(vis[i][sum]!=-1) return vis[i][sum];
        int nottake=find(i-1,sum,arr,vis);
        int take=INT_MAX;
        if(arr[i]<=sum) take=1+find(i,sum-arr[i],arr,vis);
        return vis[i][sum]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> vis(coins.size(),vector<int>(amount+1,-1));
        int ans=find(coins.size()-1,amount,coins,vis);
        if(ans==1e9) return -1;
        return ans;
    }
};