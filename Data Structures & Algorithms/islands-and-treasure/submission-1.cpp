class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cntLands = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    q.push({i, j});
                else if (grid[i][j] == INT_MAX)
                    cntLands++;
            }
        }

        if (cntLands == 0) return;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            dist++;
            
            while (sz--) {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                for (auto& d : dirs) {
                    int nr = i + d.first;
                    int nc = j + d.second;

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n 
                    || grid[nr][nc] != INT_MAX) continue;

                    grid[nr][nc] = dist;
                    q.push({nr,nc});
                    cntLands--;
                    if(cntLands==0)return;
                    
                }

            }
        }
    }
};
