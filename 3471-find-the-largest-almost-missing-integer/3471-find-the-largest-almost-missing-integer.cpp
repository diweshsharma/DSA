class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        unordered_set<int> s;
        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }

         for (int x : s) {
            f[x]++;
        }

        int i = 0;
        int j = k;
        while (j < nums.size()) {
            i++;
            j++;
            s.clear();
            for (int k = i; k < j; k++) {
                s.insert(nums[k]);
            }
            for (int x : s) {
                f[x]++;
            }
        }
        int res = -1;
        for (auto x : f) {
            if (x.second == 1) {
                res = max(res, x.first);
            }
        }return res;
    }
};