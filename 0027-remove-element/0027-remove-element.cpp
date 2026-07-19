class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                cnt++;
            }
        }
        for(int i=0;i<(n-cnt);i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                nums.push_back(val);
                i--;
            }
        }
        return (n-cnt);
    }
};