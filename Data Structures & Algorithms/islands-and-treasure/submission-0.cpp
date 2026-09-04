class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int cnt = 0;

        while (!q.empty()) {
            cnt++;
            int sz = q.size();
            while (sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != INT_MAX)
                        continue;
                    
                    grid[nx][ny] = cnt;
                    q.push({nx,ny});
                }
            }
        }

    }
};
