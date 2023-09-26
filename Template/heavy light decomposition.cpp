const int nmax = 1e4 + 10; // size check

int sub[nmax], par[nmax], depth[nmax];
vector<int> adj[nmax];
long long int a[nmax];
void dfs_sz(int u, int p = -1) {  // initially p = -1
    sub[u] = 1, par[u] = p;
    depth[u] = (p == -1) ? 0 : depth[p] + 1;
    int mx = 0;
    for(auto &v: adj[u]) {
        if(v == p) continue;
        dfs_sz(v, u);
        sub[u] += sub[v];
        if(sub[v] > mx) mx = sub[v], swap(v, adj[u][0]); 
        // swap : heavy node in first position
    }
}
int head[nmax], st[nmax], en[nmax], clk;
long long int dfsarr[nmax]; // segment tree on this array
void dfs_hld(int u, int p = -1) {
    st[u] = ++clk;
    dfsarr[clk] = a[u];  // create dfsarr
    head[u] = (p != -1 && adj[p][0] == u) ? head[p] : u;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs_hld(v, u);
    }
    en[u] = clk;
}
// not binary lifting, use chain to chain jump
int lca(int a, int b) {
    for(; head[a] != head[b]; b = par[head[b]]) {
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
    }
    if(depth[a] > depth[b]) swap(a, b);
    return a;
}
// if excl true, a will not processed
int chainProcess(int a, int u, bool excl = false) {
    for(;head[u] != head[a]; u = par[head[u]]) {
       // func(st[head[u]], st[u]); operation on seg tree
    }
    // func(st[a] + excl, st[u]); operation on seg tree
}
// pathProcess works in every case
long long int pathProcess(int a, int b, bool excl = false) {
    long long int ans = 0; // assign initial value
    for(; head[a] != head[b]; b = par[head[b]]) {
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        // func(st[head[b]], st[b]);
    }
    if(depth[a] > depth[b]) swap(a, b);
    // func(st[a] + excl, st[b]);
    return ans;
}
void hld_init(int n) {
    for(int i = 0; i <= n; i++) adj[i].clear();
}
