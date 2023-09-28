#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define PB push_back
#define fi first
#define se second
#define endl '\n'

const int nmax = 1e4 + 5; // size check

int n, sub[nmax], par[nmax], depth[nmax];
vector<int> adj[nmax];
int head[nmax], st[nmax], en[nmax], clk;
int dfsarr[nmax]; // segment tree on this array
int a[nmax];
pair<int, int> seg[4 * nmax];
int lazy[4 * nmax];
pii seg_op(pii x, pii y) {
    if(x.fi > y.fi) return x;
    else if(x.fi < y.fi) return y;
    return {x.fi, x.se + y.se};
}
void build(int pos,int l,int r) {
    lazy[pos]=0;
    if(l==r) {
        seg[pos]={0, 1};
        return;
    }
    int mid=(l+r)>>1;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);
    seg[pos]=seg_op(seg[2*pos],seg[2*pos+1]);
}
void lazy_update(int pos,int l,int r)
{
    seg[pos].fi += lazy[pos];
    if(l!=r) {
        lazy[2*pos] += lazy[pos];
        lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos]=0;
}
void update(int pos,int l,int r,int x,int y,ll val)
{
    if(lazy[pos]!=0) 
    lazy_update(pos,l,r);

    if(l>y||x>r) return;
    if(l>=x&&r<=y)
    {
        lazy[pos] += val;
        lazy_update(pos,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(2*pos,l,mid,x,y,val);
    update(2*pos+1,mid+1,r,x,y,val);
    seg[pos] = seg_op(seg[2*pos],seg[2*pos+1]);
}
// ll query(int pos,int l,int r,int x,int y)
// {
//     if(lazy[pos]!=0)
//     lazy_update(pos,l,r);

//     if(l>y||x>r) return 0;
//     if(l>=x&&r<=y) return seg[pos];
//     int mid=(l+r)>>1;
//     ll q1=query(2*pos,l,mid,x,y);
//     ll q2=query(2*pos+1,mid+1,r,x,y);
//     return seg_op(q1, q2);
// }
// initially p = -1
void dfs_sz(int u, int p = -1) {
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

void dfs_hld(int u, int p = -1) {
    st[u] = ++clk;
    // create dfsarr
    dfsarr[clk] = a[u];
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

void pathProcess(int a, int b, int val) {
    for(; head[a] != head[b]; b = par[head[b]]) {
        if(depth[head[a]] > depth[head[b]]) swap(a, b);
        // func(st[head[b]], st[b]);
        update(1, 1, n, st[head[b]], st[b], val);
    }
    if(depth[a] > depth[b]) swap(a, b);
    // func(st[a] + excl, st[b]);
    update(1, 1, n, st[a], st[b], val);
}
void hld_init(int n) {
    for(int i = 0; i <= n; i++) 
    adj[i].clear(), sub[i] = depth[i] = par[i] = 0;
    clk = 0;
}

void solve() {
    
    cin >> n;
    hld_init(n);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    build(1, 1, n);
    dfs_sz(1);
    dfs_hld(1);
    int q;
    cin >> q;
    while(q--) {
        vector<pii> v;
        int k, x, y;
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            v.PB({x, y});
            pathProcess(x, y, 1);
        }
        if(seg[1].fi == k) cout << seg[1].se << endl;
        else cout << 0 << endl;
        for(auto it : v) {
            pathProcess(it.fi, it.se, -1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}


