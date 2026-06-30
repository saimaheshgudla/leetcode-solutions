class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<nums.size();i++){
           if(i==n-1||(nums[i]!=nums[i+1])){
            temp.push_back(nums[i]);
           }
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        return temp.size();
    }
};