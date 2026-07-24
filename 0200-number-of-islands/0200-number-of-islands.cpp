class Solution {
private:
    bool valid(int row, int column, int m, int n) {
        if (row < 0 || row >= m || column < 0 || column >= n) {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j,
             vector<vector<bool>>& vis) {
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int column = j + y[k];
            if (valid(row, column, m, n) && vis[row][column] == 0 &&
                grid[row][column] == '1') {
                dfs(grid, m, n, row, column, vis);
                
            }
        }return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int i = 0;
        int j = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(grid, m, n, i, j, vis);
                    res++;
                }
            }
        }
        return res;
    }
};