class Solution {
    public:
        int atmost(vector<int> nums ,int goal){
            if(goal<0) return 0;
            int l=0;
            int r=0;
            int cnt=0;
            int sum=0;
            while(r<nums.size()){
                sum=sum+nums[r];
                while(sum>goal){
                    sum=sum-nums[l];
                    l++;
                }
                cnt=cnt+(r-l+1);
                r++;
            }
            return cnt;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal){
            return atmost(nums,goal)-atmost(nums,goal-1);
        } 
};