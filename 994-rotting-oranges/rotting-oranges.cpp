class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int res = 0, fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;
        if (q.empty())
            return -1;
        vector<pair<int, int>> xy{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int sz = q.size();
            int cnt = 0;
            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for (auto it : xy) {
                    int dx = it.first + x, dy = it.second + y;
                    if (0 <= dx && dx < n && 0 <= dy && dy < m && grid[dx][dy] == 1) {
                        cnt += 1;
                        grid[dx][dy] = 2;
                        q.push({dx, dy});
                    }
                }
            }
            if (cnt)
                res += 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return res;
    }
};