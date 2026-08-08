class Solution:
    def minEdgesReq(self, n, edges):
        if len(edges) < n - 1:
            return -1
        
        parent = list(range(n))
        rank = [0] * n
        
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx == ry:
                return
            if rank[rx] < rank[ry]:
                rx, ry = ry, rx
            parent[ry] = rx
            if rank[rx] == rank[ry]:
                rank[rx] += 1
        
        for u, v in edges:
            union(u, v)
        
        components = len(set(find(i) for i in range(n)))
        
        return components - 1