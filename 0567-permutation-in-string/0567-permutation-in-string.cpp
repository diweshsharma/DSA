class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int j = s1.size();
        
        vector<int> s11(26, 0);
        vector<int> s12(26, 0);
        
        for (int i = 0; i < j; i++) {
            s11[s1[i] - 'a']++;
            s12[s2[i] - 'a']++;
        }

        if (s11 == s12) {
            return true;
        }

        for (int i = j; i < s2.size(); i++) {
            s12[s2[i - j] - 'a']--;
            s12[s2[i] - 'a']++;
            if (s11 == s12) {
                return true;
            }
        }
        return false;
    }
};