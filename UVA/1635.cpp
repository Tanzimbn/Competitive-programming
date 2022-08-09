void solve()
{
    ll n, m;
    while(cin >> n >> m) {
        vector<pll> v;
    for(int i = 2; i*i <= m; i++) {
        int cnt = 0;
        while(m % i == 0) {
            m /= i;
            cnt++;
        }
        if(cnt != 0)
        v.PB({i,cnt});
    }
    if(m>1) v.PB({m, 1});
    n -= 1;
    map<ll,ll> mp;
    vector<ll> ans;
    for(int i = 1; i <= n; i++) {
        int yes = 1,temp = n-i+1;
        for(int j = 0; j < v.size(); j++) {
            int cnt = 0;
            while(temp%v[j].fi == 0) {
                temp /= v[j].fi;
                cnt++;
            }
            mp[v[j].fi]+=cnt;
        }
        temp = i;
        for(int j = 0; j < v.size(); j++) {
            int cnt = 0;
            while(temp%v[j].fi == 0) {
                temp /= v[j].fi;
                cnt++;
            }
            mp[v[j].fi]-=cnt;
            if(mp[v[j].fi] < v[j].se) yes = 0;
        }
        if(yes) ans.PB(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i]+1;
        if(i != ans.size()-1) cout << " ";
    }
    cout << endl;
    }
}
int main()
{
    boost_;
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++)
    {
       //cout<<"Case "<<i<<": ";
       solve();
    }
}
