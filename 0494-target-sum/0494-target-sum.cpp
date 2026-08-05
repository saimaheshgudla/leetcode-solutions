class Solution {
public:
    int cnt(int i, int sum, vector<vector<int>>& dp, vector<int>& nums) {
        if (i == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        int nottake = cnt(i - 1, sum, dp, nums);
        int take = 0;

        if (nums[i] <= sum)
            take = cnt(i - 1, sum - nums[i], dp, nums);

        return dp[i][sum] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums)
            total += x;

        if (abs(target) > total) return 0;
        if ((total + target) % 2 != 0) return 0;

        int s = (total + target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(s + 1, -1));

        return cnt(nums.size() - 1, s, dp, nums);
    }
};