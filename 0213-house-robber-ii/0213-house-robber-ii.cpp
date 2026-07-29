class Solution {
public:
    int fn(int i, vector<int>& dp, vector<int>& nums) {
        if (i == 0) return nums[0];
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + fn(i - 2, dp, nums);
        int notPick = fn(i - 1, dp, nums);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != n - 1) temp1.push_back(nums[i]); // exclude last
            if (i != 0) temp2.push_back(nums[i]);     // exclude first
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int ans1 = fn(temp1.size() - 1, dp1, temp1);
        int ans2 = fn(temp2.size() - 1, dp2, temp2);

        return max(ans1, ans2);
    }
};