class Solution {
private:
    int house(vector<int>& nums, int n, int i, int free,
              vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][free] != -1) {
            return dp[i][free];
        }
        if (free == 0) {
            return dp[i][free] = house(nums, n, i + 1, 1, dp);
        }
        int c1 = nums[i] + house(nums, n, i + 1, 0, dp);
        int c2 = house(nums, n, i + 1, 1, dp);
        return dp[i][free] = max(c1, c2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int free = 1;
        int i = 0;
        return house(nums, n, i, free, dp);
    }
};