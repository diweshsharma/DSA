class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxtill = 0;
        int res = INT_MAX;
        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            maxtill = max(maxtill, nums[i]);
            int score = maxtill - suffix[i];
            if (score <= k)
            return i;
        }
        return -1;
    }
};