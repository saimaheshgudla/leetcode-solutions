class Solution {
public:
    int atmost(vector<int> nums,int k){
        int l=0;
        int r=0;
        int cnt=0;
        int len=0;
        while(r<nums.size()){
            if(nums[r]%2!=0) cnt++;
            while(cnt>k){
                if(nums[l]%2!=0) cnt--;
                l++;
            }
            len=len+(r-l+1);
            r++;
        }
        return len;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};