from collections import deque

class Solution:
    def maxDistance(self, V, src, edges):
        adj = [[] for _ in range(V)]
        indeg = [0] * V
        for u, v, w in edges:
            adj[u].append((v, w))
            indeg[v] += 1

        # Kahn's topological sort
        q = deque(i for i in range(V) if indeg[i] == 0)
        topo = []
        while q:
            u = q.popleft()
            topo.append(u)
            for v, _ in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        NEG = -2**31          # INT_MIN
        dist = [NEG] * V
        dist[src] = 0

        for u in topo:
            if dist[u] == NEG:      # unreachable — must not relax from it
                continue
            for v, w in adj[u]:
                if dist[u] + w > dist[v]:
                    dist[v] = dist[u] + w

        return dist