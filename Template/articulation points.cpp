struct articulation_point
{
    int n; // number of nodes
    vector<vector<int>> adj; // adjacency list of graph
    vector<bool> visited;
    vector<int> tin, low;
    vector<int> ans;
    int timer;
    articulation_point (int N, vector<vector<int>> v) { 
        n = N;
        adj = v;
        visited.resize(n + 5, false);
        tin.resize(n + 5, 0); low.resize(n + 5, 0);
        timer = 0;
    }
    void IS_CUTPOINT(int a) { 
        // process the fact that vertex A is an articulation point
        ans.PB(a);
    }
    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        int children = 0, point = 0;
        for (int to : adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] >= tin[v] && p!=-1) 
                    point = 1;// this can be called multiple time for each vertex
                ++children;
            }
        }
        if(p == -1 && children > 1)
            point = 1;
        if(point) IS_CUTPOINT(v);
    }
    void find_cutpoints() {
        timer = 0;
        visited.assign(n + 5, false);
        tin.assign(n + 5, -1);
        low.assign(n + 5, -1);
        for (int i = 0; i < n; ++i) {
            // check index 0 or 1
            if (!visited[i])
                dfs(i);
        }
    }
};
