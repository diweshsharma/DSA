class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int scount = 0;
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
                scount++;

            } else {
                if (c == ')') {
                    st.pop();
                    scount--;
                }
            }
            count = max(count, scount);
        }
        return count;
    }
};