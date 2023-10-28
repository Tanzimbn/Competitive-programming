//Push-Relabel for Flows - Gap Heuristic, Complexity: O(V^2sqrt(E))
// INPUT: graph, constructed using AddEdge(), source, sink
// OUTPUT: maximum flow value, leftOfMinCut
//To obtain actual flow values, look at all edges with capacity > 0
//Zero capacity edges are residual edges
struct Edge {
    int v;
    ll flow, cap;
    int rev;
};

struct MaxFlow {
    vector<vector<Edge> > adj;
    vector<ll> excess, dist, count;
    ll b = 0, N;
    vector<bool> active;
    vector<vector<int> > B;

    MaxFlow(int n) : N(n), adj(n + 1), excess(n + 1), dist(n + 1, 0), count(n + 1), active(n + 1, 0), B(n + 1) {}
    
    void addedge(int u, int v, ll C, ll undirected = 0) {
        if(u == v) return;
        Edge a{v, 0LL, C, (int)adj[v].size()};
        Edge b{u, 0LL, undirected, (int)adj[u].size()};
        adj[u].PB(a), adj[v].PB(b); 
    } 
 
    void enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < N) {
            active[v] = 1;
            B[dist[v]].PB(v);
            b = max(b, dist[v]);
        }
    }
 
    void push (int v, Edge &e) {
        int amt = min(excess[v], e.cap-e.flow);
        if (dist[v] == dist[e.v]+1 && amt > 0) {
            e.flow += amt, adj[e.v][e.rev].flow -= amt;
            excess[e.v] += amt, excess[v] -= amt;
            enqueue(e.v);
        }
    }
 
    void gap (ll k) {
        for(int v = 0; v < N; v++) {
            if (dist[v] >= k) {
                count[dist[v]] --;
                dist[v] = N;
                count[dist[v]] ++;
                enqueue(v);
            }
        }
    }
 
    void relabel (int v) {
        count[dist[v]] --; dist[v] = N;
        for (auto e: adj[v]) if (e.cap> e.flow) dist[v] = min(dist[v], dist[e.v] + 1);
        count[dist[v]] ++;
        enqueue(v);
    }
 
    void discharge(int v) {
        for (auto &e: adj[v]) {
            if (excess[v] > 0) push(v,e);
            else break;
        }
        if (excess[v] > 0) {
            if (count[dist[v]] == 1) gap(dist[v]); 
            else relabel(v);
        }
    }
 
    ll maxFlow (int s, int t) {
        for (auto &e: adj[s]) excess[s] += e.cap;
        
        count[0] = N;
        enqueue(s); active[t] = 1;
        
        while (b >= 0) {
            cout << "b" << b << endl;
            if (B[b].size()) {
                int v = B[b].back();
                cout << "cur node" << v << endl;
                 B[b].pop_back();
                active[v] = 0; discharge(v);
            } else b--;
        }
        return excess[t];
    }
    bool leftOfMinCut(int a) { return count[a] >= N; }
};
