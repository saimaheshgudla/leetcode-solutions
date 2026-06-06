class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        int sum=nums[0];
        int rem=0;
        hash[nums[0]]=0;
        for(int i=1;i<nums.size();i++){
            rem=target-nums[i];
            auto it=hash.find(rem);
            if(it!=hash.end()){
                return{i,it->second};
            }
            hash[nums[i]]=i;
        }
        return {};
    }
};