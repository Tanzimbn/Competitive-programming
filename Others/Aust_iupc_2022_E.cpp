void solve()
{   
    ll n;
    cin >> n;
    ll a[n + 1], pos[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    int vis[n + 1] = {0};
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
      if(vis[i]) continue;
      ll val = 0, cur = i, sz = 0;
      while(vis[cur] == 0) {
        vis[cur] = 1;
        cur = pos[cur];
        if(vis[cur]) break;
        sz++;
        val += cur;
      }
      ll temp = sz * i;
      temp = min(temp, sz + (i + 1) * 2);
      ans += temp + val;
    }
    cout << ans << '\n';
}
int main()
{
    boost_;
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<":";
       solve();
    }
}