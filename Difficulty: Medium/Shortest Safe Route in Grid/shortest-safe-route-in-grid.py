from collections import deque

class Solution:
    def shortestPath(self, mat: list[list[int]]) -> int:
        n = len(mat)
        if n == 0:
            return -1
        m = len(mat[0])
        if m == 0:
            return -1

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # Step 1: mark unsafe cells (landmines + their neighbors)
        unsafe = [[False] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    unsafe[i][j] = True
                    for dx, dy in directions:
                        ni, nj = i + dx, j + dy
                        if 0 <= ni < n and 0 <= nj < m:
                            unsafe[ni][nj] = True

        # Step 2: multi-source BFS from all safe cells in column 0
        # count starts at 1 (the starting cell itself counts as a step)
        visited = [[False] * m for _ in range(n)]
        q = deque()
        for i in range(n):
            if not unsafe[i][0]:
                visited[i][0] = True
                q.append((i, 0, 1))

        while q:
            x, y, steps = q.popleft()
            if y == m - 1:
                return steps
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and not unsafe[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny, steps + 1))

        return -1