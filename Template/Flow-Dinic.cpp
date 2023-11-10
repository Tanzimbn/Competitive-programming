
const long long flow_inf = 1e18;
struct FlowEdge {
  int v,u,id; long long cap, flow = 0;
  FlowEdge(int v, int u, long long cap,int id=-1) : v(v), u(u), cap(cap),id(id) {}
};
struct Dinic
{
  vector<FlowEdge> edges; vector<vector<int> > adj;
  int n, m = 0; int s, t;
  vector<int> level, ptr,flow_through;
  queue<int> q; vector<bool>vis;
  int maxid=0;
  Dinic() {}
  Dinic(int n) : n(n) {
    vis.resize(n); adj.resize(n);
    level.resize(n); ptr.resize(n);
  }
  void add_edge(int v, int u, long long cap,int id=-1) {
    edges.emplace_back(v, u, cap,id);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
    if(id!=-1)maxid++;
  }
  void dfs2(int s) {
    vis[s] = 1;
    for(int i:adj[s]) {
      int id = i; int u = edges[id].v;
      int v = edges[id].u;
      if(edges[id].flow!=edges[id].cap && !vis[v])
      {
        dfs2(v);
      }
    }
  }
  vector<int> getMinCut() {
    dfs2(s); vector<int>ret;
    for(int i=0; i<n; i++) {
      if(vis[i]) ret.push_back(i);
    }
    return ret;
  }
  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v])
      {
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].u] != -1)
          continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }
  long long dfs(int v, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++){
      int id = adj[v][cid]; int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr; edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
  long long flow(int _s,int _t) {
    s=_s; t=_t;
    long long f = 0;
    while (true)
    {
      fill(level.begin(), level.end(), -1);
      level[s] = 0; q.push(s);
      if (!bfs()) break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)){
        f += pushed;
      }
    }
    flow_through.assign(maxid+1, 0);
    for(int i = 0; i < n; i++){
      for(auto j : adj[i]) {
        int idx = j;
        FlowEdge e = edges[idx];
        if(e.id >= 0)flow_through[e.id] = e.flow;
      }
    }
    return f;
  }
};
