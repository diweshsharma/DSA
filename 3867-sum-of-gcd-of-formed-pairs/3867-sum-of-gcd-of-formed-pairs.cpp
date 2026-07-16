class Solution {
private:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

public:
    long long gcdSum(vector<int>& nums) {

        long long sum = 0;
        vector<int> prefixGcd;
        int mxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            mxi = max(mxi, nums[i]);
            prefixGcd.push_back(gcd(nums[i], mxi));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int k = 0;
        int q = prefixGcd.size() - 1;
        while (k < q) {
            sum += gcd(prefixGcd[k], prefixGcd[q]);
            k++;
            q--;
        }
        return sum;
    }
};