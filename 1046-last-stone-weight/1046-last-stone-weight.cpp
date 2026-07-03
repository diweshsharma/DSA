class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto i : stones) {
            pq.push(i);
        }

        while (!pq.empty()) {
            int y = pq.top();
            pq.pop();

            if (pq.empty()) {
                return y;
            } else {

                int x = pq.top();
                pq.pop();

                if (x == y) {
                    continue;
                } else {
                    y = y - x;
                    pq.push(y);
                }
            }
        }
        
        return 0;
    }
};