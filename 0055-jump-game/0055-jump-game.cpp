class Solution {
public:
    bool canJump(vector<int>& nums) {
        int most = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > most) {
                return false;
            }
            most = max(most, i + nums[i]);
            if (most > nums.size() - 1)
            {
                return true;
            }
        }return true;
    }
};