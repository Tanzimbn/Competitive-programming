const int N= 1e5+5; // check
int sub[N],par[N];
set<int> Tree[N];
int get_sub(int u,int p){

    sub[u]=1;
    for(auto v : Tree[u]){
        if(v!=p) sub[u]+=get_sub(v,u);
    }
    return sub[u];
}
int get_centroid(int u,int p,int n){

    for(auto v:Tree[u]){
        if(v!=p and sub[v]>n/2)
        return get_centroid(v,u,n);
    }
    return u;
}
void build_centroid(int u,int p){
    int n=get_sub(u,p);
    int centroid=get_centroid(u,p,n);
    if(p==-1) p=centroid;
    par[centroid]=p;
    // for each Tree resulting from the removal of the centroid
    for(auto v:Tree[centroid]){
        Tree[v].erase(centroid);
        build_centroid(v,centroid);
    }
    return;
}
