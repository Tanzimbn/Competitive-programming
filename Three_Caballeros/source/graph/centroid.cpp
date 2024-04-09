const int N= 2e5+5; // check
int sub[N], par[N], lvl[N], vis[N], cnt[N];
vector<int> Tree[N];
int get_sub(int u,int p) {
    sub[u]=1;
    for(auto v : Tree[u]){
        if(v != p && vis[v] == 0) sub[u]+=get_sub(v, u);
    }
    return sub[u];
}
int get_centroid(int u,int p,int n) {
    for(auto v:Tree[u]){
        if(vis[v]) continue;
        if(v != p && sub[v] > n/2)
        return get_centroid(v, u, n);
    }
    return u;
}
void add_centroid(int x, int y) {
    par[y] = x;
    lvl[y] = lvl[x] + 1;
    vis[y] = 1;
}
void build_centroid(int u,int p = -1) {
    int n=get_sub(u,p); // subtree size
    int centroid = get_centroid(u,p,n);
    if(p == -1) p = centroid;
    add_centroid(p, centroid);
    for(auto v : Tree[centroid]){
        if(vis[v]) continue;
        build_centroid(v, centroid);
    }
}
