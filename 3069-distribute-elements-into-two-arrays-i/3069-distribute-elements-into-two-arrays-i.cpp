class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if(nums.size()<=1){
            return nums;
        }
        vector<int> arr1;
        vector<int>arr2;
        int prev1=0;
        int prev2=0;
        int i=0;
        while(i<nums.size()){
            if(i==0 && nums.size()>1){
                arr1.push_back(nums[0]);
                arr2.push_back(nums[1]);
                i++;
                i++;
                prev1=nums[0];
                prev2=nums[1];
            }
            else if(prev1>=prev2) {
                arr1.push_back(nums[i]);
                prev1=nums[i];
                i++;
            }
            else{
                arr2.push_back(nums[i]);
                prev2=nums[i];
                i++;
            }
        }
        for(int j=0;j<arr2.size();j++){
            arr1.push_back(arr2[j]);
        }
        return arr1;
    }
};