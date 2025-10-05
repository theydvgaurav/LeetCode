class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []

        n, m = len(heights), len(heights[0])
        pac, atl = set(), set()

        def dfs(r, c, visited):
            visited.add((r, c))
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc
                if (0 <= nr < n and 0 <= nc < m and
                    (nr, nc) not in visited and
                    heights[nr][nc] >= heights[r][c]):
                    dfs(nr, nc, visited)

        # Pacific edges
        for i in range(n):
            dfs(i, 0, pac)
        for j in range(m):
            dfs(0, j, pac)

        # Atlantic edges
        for i in range(n):
            dfs(i, m - 1, atl)
        for j in range(m):
            dfs(n - 1, j, atl)

        return list(pac & atl)