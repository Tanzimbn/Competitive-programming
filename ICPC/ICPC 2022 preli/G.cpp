ll n, r, a[5005], dis[5001][5001];
ll dp[5001][301];
void solve()
{
    cin >> n >> r;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(r >= n) {
        cout << -1 << '\n'; // impossible case
        return;
    }
    for(int i = 2; i <= n; i++) {
        dis[i][i] = 0;
        for(int j = i + 1; j <= n; j++) {
            int mid = (i + j) / 2;
            dis[i][j] = dis[i][j - 1] + (a[j] - a[mid]);
        }
        for(int j = 0; j <= r; j++) dp[i][j] = 1e18;
    }
    for(int i = 1; i <= n; i++) {
        dis[1][i] = dis[1][i - 1] + (a[i] - a[1]);
    }
    for(int i = 0; i <= n - r; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= r && j < i; j++) {
            if(r - j > n - i) continue; // impossible case for remaining roads and remaining nodes
            for(int k = 0; k <= j; k++) {
                if(i - k - 1 <= j - k && j - k != 0) continue;
                ll val = dp[i - k - 1][j - k] + dis[i - k][i];
                dp[i][j] = min(dp[i][j], val);
            }
        }
    }
    cout << dp[n][r] << '\n';

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
