class Solution {
private:
    bool vowel(char c) { return c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u'; }

public:
    int maxVowels(string s, int k) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (vowel(s[i])) {
                count++;
                
            }
            res = count;
        }
        for (int i = k; i < s.size(); i++) {
            if (vowel(s[i - k])) {
                count--;
            }
            if (vowel(s[i])) {
                count++;
            }
            res = max(res, count);
        }
        return res;
    }
};