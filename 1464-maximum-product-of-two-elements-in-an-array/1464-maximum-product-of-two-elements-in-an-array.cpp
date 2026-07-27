class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if (n == 2) {
            ans = (nums[0] - 1) * (nums[1] - 1);
        } else {
            int num1 = 0;
            int num2 = n -1 ;
            for (int i = 1; i < n; i++) {
                if (nums[i] >= nums[num1]) {
                    num2 = num1;
                    num1 = i;
                } else {
                    if (nums[i] >= nums[num2]) {
                        num2 = i;
                    }
                }
            }
            ans =  (nums[num1] - 1) * (nums[num2] - 1);
        }

        return ans;
    }
};