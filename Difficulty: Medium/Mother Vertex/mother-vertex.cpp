class Solution {
public:
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V), revAdj(V);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            revAdj[e[1]].push_back(e[0]);
        }
        
        vector<char> vis(V, 0);
        int cand = -1;
        
        auto dfs1 = [&](auto& self, int u) -> void {
            vis[u] = 1;
            for (int v : adj[u]) {
                if (!vis[v]) self(self, v);
            }
            cand = u;
        };
        
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) dfs1(dfs1, i);
        }
        
        fill(vis.begin(), vis.end(), 0);
        int cnt = 0;
        
        auto dfs2 = [&](auto& self, int u) -> void {
            vis[u] = 1;
            cnt++;
            for (int v : adj[u]) {
                if (!vis[v]) self(self, v);
            }
        };
        
        dfs2(dfs2, cand);
        
        if (cnt != V) return -1;
        
        fill(vis.begin(), vis.end(), 0);
        int minMother = cand;
        
        auto dfs3 = [&](auto& self, int u) -> void {
            vis[u] = 1;
            if (u < minMother) minMother = u;
            for (int v : revAdj[u]) {
                if (!vis[v]) self(self, v);
            }
        };
        
        dfs3(dfs3, cand);
        
        return minMother;
    }
};