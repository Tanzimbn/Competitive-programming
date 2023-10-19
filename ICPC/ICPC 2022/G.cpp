ll mn[5005];
bool check(vector<vector<pair<ll,ll> > > adj, ll n, ll s, ll t, ll c, ll d, ll mid) {
  vector< vector<ll> > dp(n + 2, vector<ll> (mid + 2, INFLL));
  dp[s][mid] = 0;
  priority_queue<pair<ll,pair<pll, ll> > > pq;
  pq.push({0, {{mid, s}, -1}});
  while(!pq.empty()) {
    ll val = -pq.top().fi;
    pair<pll, ll> pos = pq.top().se;
    pq.pop();
    if(pos.fi.fi == 0) {
        continue;
    }
    if(val != dp[pos.fi.se][pos.fi.fi]) continue;
    // cout << pos.se << pos.fi << endl;
    for(auto it : adj[pos.fi.se]) {
        // pos.fi.se -> it.fi
        if(pos.se != it.fi && dp[it.fi][pos.fi.fi - 1] > val + it.se) {
            dp[it.fi][pos.fi.fi - 1] = val + it.se;
            pq.push({-dp[it.fi][pos.fi.fi - 1], {{pos.fi.fi - 1, it.fi}, pos.fi.se}});
        }
        // pos.fi.se -> it.fi -back-jump- pos.fi.se
        if(dp[pos.fi.se][mid] > dp[pos.fi.se][pos.fi.fi] + mn[pos.fi.se] + d) {
            dp[pos.fi.se][mid] = dp[pos.fi.se][pos.fi.fi] + mn[pos.fi.se] + d;
            pq.push({-dp[pos.fi.se][mid], {{mid, pos.fi.se}, it.fi}});
        }
        // pos.fi.se -> it.fi -back-jump- pos.fi.se -back-jump- it.fi
        ll val1 = dp[pos.fi.se][pos.fi.fi] + it.se + 2 * d;
        // pos.fi.se -> it.fi -back-jump- pos.fi.se -> it.fi
        if(pos.fi.fi >= 2) 
        val1 = min(val1, dp[pos.fi.se][pos.fi.fi] + it.se + mn[it.fi] + d);
        if(dp[it.fi][mid] > val1) {
            dp[it.fi][mid] = val1;
            pq.push({-dp[it.fi][mid], {{mid, it.fi}, pos.fi.se}});
        }
    }
  }
  for(int i = 1; i <= mid; i++) {
    if(dp[t][i] <= c) return true;
  }
  return false;
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
  if(a.se < b.se) return true;
  return false;
}
void solve()
{   
    ll n,m, s, dt, c, d;
    cin >> n >> m >> s >> dt >> c >> d;
    vector<vector<pair<ll,ll> > > adj(n + 2);
    map<pair<ll, ll> , ll> mp;
    for(int i = 0; i <= n; i++) mn[i] = INFLL;
    for(int i = 0; i < m; i++) {
      ll x, y, w;
      cin >> x >> y >> w;
      if(mp.count({x, y})) mp[{x, y}] = min(mp[{x, y}], w);
      else mp[{x, y}] = w;
    }
    for(auto it : mp) {
      adj[it.fi.fi].PB({it.fi.se, it.se});
      adj[it.fi.se].PB({it.fi.fi, it.se});
      mn[it.fi.fi] = min(mn[it.fi.fi], it.se);
      mn[it.fi.se] = min(mn[it.fi.se], it.se);
    }
    ll l = 1, r = n, ans = -1;
    while(l <= r) {
      ll mid = (l + r) / 2;
      if(check(adj, n, s, dt, c, d, mid)) {
        ans = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }
    if(ans == -1) cout << "Impossible\n";
    else cout << ans << endl;
} 
int main()
{
    boost_;
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
      cout<<"Case "<<i<<": ";
       solve();
    }
}
