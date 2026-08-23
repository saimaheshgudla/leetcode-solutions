class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev=0;
        vector<int> num;
        for(int i=0;i<nums.size();i++){
            if(i==0) {
                prev=nums[i];
                num.push_back(nums[i]);
            }
            else{
                if(prev==nums[i]){
                    continue;
                }
                else{
                    num.push_back(nums[i]);
                    prev=nums[i];
                }
            }
        }
        if(num.size()<3) return num[num.size()-1];
        return num[num.size()-3];
    }
};