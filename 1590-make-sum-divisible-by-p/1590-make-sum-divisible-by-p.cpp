class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        int len = INT_MAX;
        unordered_map<int, int> f;
        f[0] = -1;
        for (int num : nums) {
            sum += num;
        }
        long long target = sum % p;
        if (target == 0)
            return 0;

        long long total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
            long long rem = total_sum % p;

            long long demand = (rem - target + p) % p;
            if (f.count(demand)) {
                int idx = f[demand];
                len = min(len, i - idx);
            }
            // if (!f.count(rem)) {}
            f[rem] = i;
        }

        return (len == INT_MAX || len == (int)nums.size()) ? -1 : len;
    }
};