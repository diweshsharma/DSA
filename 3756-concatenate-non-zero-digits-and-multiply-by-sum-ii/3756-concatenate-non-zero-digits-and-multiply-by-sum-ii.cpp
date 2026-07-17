class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> digitSum(n + 1, 0);
        vector<int> nonZeroCnt(n + 1, 0);
        vector<long long> prefValue(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            digitSum[i] = digitSum[i - 1] + d;
            nonZeroCnt[i] = nonZeroCnt[i - 1] + (d != 0);

            if (d != 0)
                prefValue[i] = (prefValue[i - 1] * 10 + d) % MOD;
            else
                prefValue[i] = prefValue[i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = digitSum[r + 1] - digitSum[l];

            int cnt = nonZeroCnt[r + 1] - nonZeroCnt[l];

            long long x =
                (prefValue[r + 1] -
                 prefValue[l] * pow10[cnt] % MOD +
                 MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};