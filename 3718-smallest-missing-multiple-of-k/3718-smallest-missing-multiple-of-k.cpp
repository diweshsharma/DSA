class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int num = 1;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (int i = 1; i <= nums.size() + 1; i++) {
            num = k * i;
            if (mp.find(num) != mp.end()) {
                continue;
            } else {
                res = min(res, num);
            }
        }return res;
    }
};