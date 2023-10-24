// O(VE^2)
// handle multiple edge between two vertex 
long long max_flow(vector<vector<long long>> adj, vector<vector<long long>> &g, int n, int source, int sink) {
    // graph edge - number of vertex - source - sink    
    long long flow = 0;
    vector<int> parent(n, -1);

    // Find a way from the source to sink on a path with non-negative capacities
    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto son : adj[node]) {
                long long w = g[node][son];
                if (w <= 0 || parent[son] != -1) continue;
                parent[son] = node;
                q.push(son);
            }
        }
        return parent[sink] != -1;
    };

    // While there is a way from source to sink with non-negative capacities
    while (reachable()) {
        int node = sink;
        // The minimum capacity on the path from source to sink
        long long curr_flow = LLONG_MAX;
        while (node != source) {
            curr_flow = min(curr_flow, g[parent[node]][node]);
            node = parent[node];
        }
        node = sink;
        while (node != source) {
            // Subtract the capacity from capacity edges
            g[parent[node]][node] -= curr_flow;
            // Add the current flow to flow backedges
            g[node][parent[node]] += curr_flow;
            node = parent[node];
        }
        flow += curr_flow;
        fill(parent.begin(), parent.end(), -1);
    }
    return flow;
}
