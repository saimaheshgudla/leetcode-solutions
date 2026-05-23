class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        int cnt=0;
        int maxlen=0;
        while(r<nums.size()){
            if(nums[r]==0) cnt++;
            while(cnt>k){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};