class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int minCol = INT_MAX, maxCol = -1, minRow = INT_MAX, maxRow = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                }
            }
        }
        return (maxCol - minCol + 1) * (maxRow - minRow + 1);
    }
};