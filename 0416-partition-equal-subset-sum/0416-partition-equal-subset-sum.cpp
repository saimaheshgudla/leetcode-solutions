class Solution {
public:
    bool find(int i,int sum,vector<vector<int>>& vis,vector<int>& arr){
        if(sum==0) return true;
        if(i==0) return(arr[i]==sum);
        if(vis[i][sum]!=-1) return vis[i][sum];
        bool nottake=find(i-1,sum,vis,arr);
        bool take =false;
        if(arr[i]<=sum) take=find(i-1,sum-arr[i],vis,arr);
        return vis[i][sum]=take | nottake; 
    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
       }
        int s=sum/2;
        if(sum!=2*s) return false;
        vector<vector<int>> vis(nums.size(),vector<int>(s+1,-1));
        return find(nums.size()-1,s,vis,nums);
   }
};