class Solution {
    int lis(vector<int>& nums, int n, int i, int prev,
            vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        if (prev == -1 || nums[prev] < nums[i]) {
            int c1 = 1 + lis(nums, n, i + 1, i, dp);
            int c2 = lis(nums, n, i + 1, prev, dp);
            return dp[i][prev + 1] = max(c1, c2);
        }
        return dp[i][prev + 1] = lis(nums, n, i + 1, prev, dp);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int prev = -1;
        int i = 0;
        return lis(nums, n, i, prev, dp);
    }
};