class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int> freq;
        unordered_map<char, int> fr;

        for (int i = 0; i < m; i++) {
            freq[tasks[i]]++;
            fr[tasks[i]] = 1;
        }

        priority_queue<pair<int, char>> pq;
        for (auto i : freq) pq.push({i.second, i.first});

        int seat = 1;
        bool placed = false;

        while (!pq.empty()) {
            vector<pair<int, char>> pull;
            placed = false;

            while (!pq.empty()) {
                pair<int, char> p = pq.top(); pq.pop();
                char element = p.second;

                if (fr[element] <= seat) {
                    seat++;                    
                    placed = true;
                    if (p.first > 1) {
                        pq.push({p.first - 1, p.second});
                        fr[element] = seat + n;  
                    }
                    break;
                } else {
                    pull.push_back(p);
                }
            }

            for (auto& x : pull) pq.push(x);

            
            if (!placed && !pq.empty()) seat++;
        }
        return seat - 1;
    }
};