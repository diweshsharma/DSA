class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxel = nums[0];
        int minel = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            maxel = max(maxel, nums[i]);
            minel = min(minel, nums[i]);
        }

        vector<int> res;
        for (int i = minel; i <= maxel; i++) {
            if (mp.find(i) != mp.end()) {
                continue;
            } else {
                res.push_back(i);
            }
        }return res;
    }
};