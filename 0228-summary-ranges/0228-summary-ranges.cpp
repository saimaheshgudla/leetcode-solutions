class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        int prev=nums[0];
        int cnt=nums[0];
        for(int i=1;i<nums.size();i++){
            if(prev+1!=nums[i]){
                if(cnt==prev) ans.push_back(to_string(cnt));
                else{
                    string ch=to_string(cnt);
                    ch=ch+"->";
                    ch=ch+to_string(prev);
                    ans.push_back(ch);
                }
                cnt=nums[i];
            }
            prev=nums[i];
        }

        if(cnt==prev)
            ans.push_back(to_string(cnt));
        else{
            string ch=to_string(cnt);
            ch=ch+"->";
            ch=ch+to_string(prev);
            ans.push_back(ch);
        }
        return ans;
    }
};