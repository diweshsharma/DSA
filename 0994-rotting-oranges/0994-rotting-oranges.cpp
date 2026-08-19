class Solution {
private:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int row, int column, int m, int n) {
        if (row < 0 or row >= m or column < 0 or column >= n) {
            return false;
        }
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (!q.empty() && fresh > 0) {
            time++;
            int s = q.size();
            while (s--) {
                pair<int, int> p = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int row = p.first + x[k];
                    int column = p.second + y[k];
                    if (valid(row, column, m, n) && grid[row][column] == 1) {
                        q.push({row, column});
                        grid[row][column] = -2;
                        fresh--;
                    }
                }
            }
        }
        if(fresh > 0){
            time = -1;
        }
        return time;
    }
};