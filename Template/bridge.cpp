struct bridge
{
    int n; // number of nodes
    vector<vector<int>> adj; // adjacency list of graph
    vector<bool> visited;
    vector<int> tin, low;
    vector<pii> edge;
    int timer;
    bridge (int N, vector<vector<int>> v) { 
        n = N; 
        adj = v;
    }
    void IS_BRIDGE(int x, int y) { 
        edge.PB({x, y});
    }
    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for (int to : adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v]) 
                    IS_BRIDGE(v, to); 
            }
        }
    }
    void find_bridge() {
        timer = 0;
        visited.assign(n + 5, false);
        tin.assign(n + 5, -1);
        low.assign(n + 5, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs (i);
        }
    }
};
