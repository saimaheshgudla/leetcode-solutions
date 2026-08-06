class Solution {
public:
    int fn(int i,int sum,vector<vector<int>>& vis,vector<int>& arr){
        if(i==0){
            return sum%arr[i]==0;
        }
        if(vis[i][sum]!=-1) return vis[i][sum];
        int nottake=fn(i-1,sum,vis,arr);
        int take=0;
        if(arr[i]<=sum) take=fn(i,sum-arr[i],vis,arr);
        return vis[i][sum]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> vis(n,vector<int>(amount+1,-1));
        return fn(n-1,amount,vis,coins);
    }
};