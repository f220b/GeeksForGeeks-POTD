class Solution:
    def isNegativeWeightCycle(self, V: int, edges: list[list[int]]) -> bool:
        dist = [0] * V

        for _ in range(V - 1):
            for u, v, w in edges:
                dist[v] = min(dist[v], dist[u] + w)
                
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                return True
        
        return False