class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        
        int i = 0;
        long long sum = 0;
        long long totalsum = 0;
        while (i < s.size()) {
            if (s[i] != '0') {
                sum = sum * 10 + (s[i] - '0');
                totalsum += (s[i] - '0');
            }
            i++;
        }return sum * totalsum;
    }
};