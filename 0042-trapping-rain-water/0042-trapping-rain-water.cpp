class Solution {
public:
    vector<int>rightmaxi(vector<int> arr){
        vector<int> res(arr.size(),0);
        int maxi=-1;
        for(int i=arr.size()-1;i>=0;i--){
            maxi=max(maxi,arr[i]);
            res[i]=maxi;
        }
        return res;
    }
    vector<int> leftmaxi(vector<int>nums){
        vector<int> res(nums.size(),0);
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            res[i]=maxi;
        }
        return res;
    }
    int trap(vector<int>& height) {
        int total=0;
        vector<int> leftmax=leftmaxi(height);
        vector<int> rightmax=rightmaxi(height);
        for(int i=0;i<height.size();i++){
            if(leftmax[i]>height[i] && rightmax[i]>height[i]){
                total+=min(leftmax[i],rightmax[i])-height[i];
            }
        }
        return total;
    }
};