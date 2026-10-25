class Solution {
    int n, m;
    bool dfs(int r, int c, vector<vector<int>>& g) {
        if (r < 0 || r >= n || c < 0 || c >= m) return false;
        if (g[r][c] == 1) return true;
        g[r][c] = 1;
        bool d1 = dfs(r + 1, c, g), d2 = dfs(r - 1, c, g);
        bool d3 = dfs(r, c + 1, g), d4 = dfs(r, c - 1, g);
        return d1 & d2 & d3 & d4;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && dfs(i, j, grid)) {
                    count++;
                }
            }
        }
        return count;
    }
};
