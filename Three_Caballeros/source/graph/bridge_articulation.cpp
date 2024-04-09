const int MAX_N = 1e5 + 1;
// dfs_num[u] stores the iteration counter when DFS visits node u for the 1st time
// dfs_low[u] stores the lowest dfs_num reachable from the current DFS spanning subtree of node u
// dfs_low[u] can only be made smaller if there is a back edge to form a cycle and v is currently visited
 
int n, m, dfsCounter;
int dfs_num[MAX_N], dfs_low[MAX_N], visited[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u, int p = -1) {
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    visited[u] = 1;
    int num_child = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        // back edge
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        // tree edge
        else {
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            num_child++;
            if (dfs_low[v] > dfs_num[u])
                cout << "Edge " << u << "-" << v << " is a bridge\n";
            if (dfs_low[v] >= dfs_num[u] && p != -1)
                cout << "Node " << u << " is an articulation point\n";
        }
    }
    // special case: the root node is an articulation point if it has more than 1 child
    if (p == -1 && num_child > 1)
        cout << "Node " << u << " is an articulation point\n";
}
 
void solve() {
    // take input graph
    memset(dfs_low, -1, sizeof dfs_low);
    memset(dfs_num, -1, sizeof dfs_num);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
}
