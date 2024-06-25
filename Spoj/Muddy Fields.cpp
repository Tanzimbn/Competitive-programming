#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

void solve() {

    int n, m;
    cin >> n >> m;

    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];

    int row[50][50], col[50][50];
    

    function<bool(int, int)> check = [&] (int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(s[x][y] == 'o') return false;
        return true;
    };

    int r = 0, c = 0;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') cnt = 0;
            else {
                if(cnt == 0) r++;
                row[i][j] = r;
                cnt++;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(s[j][i] == '.') cnt = 0;
            else {
                if(cnt == 0) c++;
                col[j][i] = c;
                cnt++;
            }
        }
    }

    Hopcroft_Karp bpm(r, c);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') continue;
            bpm.addEdge(row[i][j], col[i][j]);
        }
    }

    cout << bpm.max_matching() << endl;
}
int main()
{
    // boost_;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout<<"Case "<<i<<": ";
       solve();
    }
}
