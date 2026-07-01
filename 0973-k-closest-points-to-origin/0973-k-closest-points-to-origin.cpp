class Solution {
private:
    
    float distance(int x, int y) {
        
        return sqrt(x*x + y*y);
    }

private:
    struct cmp {
        bool operator()(pair<float, int>& a, pair<float, int>& b) {
            return a.first < b.first;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue < pair<float, int>, vector<pair<float, int>>, cmp> pq;

        unordered_map<int, float> f;

        for (int i = 0; i < n; i++) {
            f[i] = distance(points[i][0], points[i][1]);
        }

        for (auto i : f) {
            int idx = i.first;
            float dist = i.second;

            pair<float, int> curr = {dist,idx};
            if(pq.size() < k){
                pq.push(curr);
                continue;
            }
           else{
            if (curr.first > pq.top().first) {
                continue;
            }
            else {
                pq.pop();
                pq.push(curr);
            }
        }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            int x = pq.top().second;
            res.push_back(points[x]);
            pq.pop();
            
        }
        return res;
    }
};