class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int cnt=0;
        int i=0;
        while(i<nums.size()){
            if(mpp[nums[i]]>2){
                int val = nums[i];
                nums.erase(nums.begin()+i);
                mpp[val]--;
                cnt++;
            }
            else i++;
        }
        return n-cnt;
    }
};