const int mx=2e5+2;
int L[mx]; //lvl
int P[mx][22]; //sparse table
int T[mx]; //parent
vector<int>g[mx];
int cnt[mx];
int v[mx];
void dfs(int u,int from,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(v,u,dep+1);
    }
}
 
int lca_query(int N, int p, int q) //N=number of node
  {
      int tmp, log, i;
 
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
 
        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
 
      }
 
        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
 
      if (p == q)
          return p;
 
        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
 
      return T[p];
  }
 
void lca_init(int N)
  {
      memset (P,-1,sizeof(P)); //intially all -1
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];
 
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
