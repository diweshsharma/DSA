class Solution {
private:
    int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

public:
    int findGCD(vector<int>& nums) {
        int min_no = nums[0];
        int max_no = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            min_no = min(min_no, nums[i]);
            max_no = max(max_no, nums[i]);
        }
        return gcd(min_no , max_no);
    }
};