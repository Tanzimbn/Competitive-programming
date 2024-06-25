/// maximum independent set = n - max matching
/// minimum vertex cover = max matching
/// minimum edge cover = n - max matching
/// minimum path cover(vertex disjoint) on DAG: Take each node twice to construct a bipartite graph.
/// If the DAG has edge u to v the bipartite graph has edge from u of left side to v of right side.
/// minimum path cover = n - max matching where n is the number of nodes in DAG
/// Minimum Path Cover (Vertex not Disjoint) in General Graph: Create SCC graph. Take each node twice to construct a bipartite graph.
/// If in the DAG(SCC graph) vertex v is reachable from u then add edge from u of left side to v of right side in the bipartite graph
/// Reachability can be checked using by calling bfs n times where n is the number of nodes in SCC graph.
/// minimum path cover = n - max matching where n is the number of nodes in SCC graph
// 1 indexed Hopcroft-Karp Matching in O(E sqrtV)
// Add edge from left side to right side
struct Hopcroft_Karp
{
    static const int inf = 1e9;
    int n;
    vector<int> matchL, matchR, dist;
    vector<vector<int> > g;
    Hopcroft_Karp(int n, int m) : n(n), matchL(n+1),matchR(m+1), dist(n+1), g(n+1) {}
    void addEdge(int u, int v) {
        g[u].push_back(v);
    }
    bool bfs()
    {
        queue<int> q;
        for(int u=1;u<=n;u++) {
            if(!matchL[u]) {
                dist[u]=0;
                q.push(u);
            }
            else
            dist[u]=inf;
        }
        dist[0]=inf;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:g[u])
            {
                if(dist[matchR[v]] == inf)
                {
                    dist[matchR[v]] = dist[u] + 1;
                    q.push(matchR[v]);
                }
            }
        }
        return (dist[0]!=inf);
    }
    bool dfs(int u)
    {
        if(!u) return true;
        for(auto v:g[u])
        {
            if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v])) {
                matchL[u]=v;
                matchR[v]=u;
                return true;
            }
        }
        dist[u]=inf;
        return false;
    }
    int max_matching()
    {
        int matching=0;
        while(bfs()) {
            for(int u=1;u<=n;u++) {
                if(!matchL[u]) if(dfs(u))
                matching++;
            }
        }
        return matching;
    }
};