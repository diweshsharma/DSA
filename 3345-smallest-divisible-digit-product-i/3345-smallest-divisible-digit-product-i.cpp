class Solution {
public:
    int smallestNumber(int n, int t) {
        
        int number = n;
        int ans = 0;
        while (true) {
            n = number;
            int prod = 1;
            while (n > 0) {
                prod *= n % 10;
                n /= 10;
                if (prod % t == 0) {
                    return number;
                }
            }
            number++;
        }
        return ans;
    }
};