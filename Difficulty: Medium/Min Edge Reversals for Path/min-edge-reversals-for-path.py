from collections import deque

class Solution:
    def minimumEdgeReversal(self, edges, n, src, dst):
        adj = [[] for _ in range(n + 1)]

        for edge in edges:
            u = edge[0]
            v = edge[1]
            adj[u].append([v, 0])
            adj[v].append([u, 1])

        dist = [float('inf')] * (n + 1)

        dq = deque()
        dist[src] = 0
        dq.appendleft(src)

        while dq:
            node = dq.popleft()

            for edge in adj[node]:
                next = edge[0]
                cost = edge[1]

                if dist[node] + cost < dist[next]:
                    dist[next] = dist[node] + cost

                    if cost == 0:
                        dq.appendleft(next)
                    else:
                        dq.append(next)

        if dist[dst] == float('inf'):
            return -1

        return dist[dst]