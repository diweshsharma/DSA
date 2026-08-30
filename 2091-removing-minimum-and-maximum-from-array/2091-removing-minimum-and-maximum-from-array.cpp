class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minn = INT_MAX;
        int maxn = INT_MIN;
        int maxindex = -1;
        int minindex = -1;
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minn) {
                minn = nums[i];
                minindex = i;
            }

            if (nums[i] > maxn) {
                maxn = nums[i];
                maxindex = i;
            }
        }
      if (minindex > maxindex) {
            swap(minindex, maxindex);
        }

        int left = maxindex + 1;
        int right = n - minindex;
        int both = minindex + 1 + (n - maxindex);

        return min({left, right, both});
    }
};