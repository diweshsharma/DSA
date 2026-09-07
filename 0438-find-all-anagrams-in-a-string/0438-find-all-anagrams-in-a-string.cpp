class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        int j = p.size();

        vector<int> s1(26, 0);
        vector<int> p1(26, 0);

        vector<int> res;
        int i;
        

        for (i = 0; i < j; i++) {
            s1[s[i] - 'a']++;
            p1[p[i] - 'a']++;
        }
        if (s1 == p1) {
            res.push_back(0);
            
        }

        for (i = j; i < s.size(); i++) {
            s1[s[i - j] - 'a']--;
            s1[s[i] - 'a']++;
            if (s1 == p1) {
                res.push_back(i - j + 1);
            }
        }
        return res;
    }
};