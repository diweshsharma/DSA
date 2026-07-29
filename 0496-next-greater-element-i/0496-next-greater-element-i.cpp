class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> next;
        vector<int> res;
        stack<int> st;
        st.push(nums2[n - 1]);
        next[nums2[n - 1]] = -1;

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i] ) {
                st.pop();
            }
            if (st.empty()) {
                next[nums2[i]] = -1;
            } else {
                next[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(next[nums1[i]]);
        }
        return res;
    }
};