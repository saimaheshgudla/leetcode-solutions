class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        for(auto c:nums1){
            if(find(nums2.begin(),nums2.end(),c)!=nums2.end()){
                mpp[c]++;
            }
        }
        vector<int>nums;
        for(auto it:mpp){
            nums.push_back(it.first);
        }
        return nums;
    }
};