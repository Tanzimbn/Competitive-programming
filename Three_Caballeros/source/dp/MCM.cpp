const int mx = 100 + 9;
const ll inf = 9e18;
struct Matrix {
    int row, col;
    Matrix(int _row, int _col) {
        row = _row;
        col = _col;
    }
};
vector <Matrix> mats;
ll dp[mx][mx];
int mergeCost(int i, int j, int k) {
    return mats[i].row * mats[k].col * mats[j].col;
}
ll solve(int l, int r) {
    if (l >= r) return 0;
 
    ll& ans = dp[l][r];
    if (ans != -1) return ans;
 
    ans = inf;
    for (int i = l; i < r; i++) {
        ll left = solve(l, i);
        ll right = solve(i + 1, r);
        ll cost = mergeCost(l, r, i) + (left + right);
        ans = min(ans, cost);
    }
 
    return ans;
}
int evaluate(int i, int j) {
    if (i >= j) {
        return 0;
    }
 
    return dp[i][j];
}
 
ll solve() {
    int n = mats.size();
    for (int sz = 1; sz <= n; sz++) {
        for (int i = 0; i < n; i++) {
            int j = i + sz - 1;
            if (j >= n) break;
 
            ll ans = inf;
            for(int k = i; k < j; k++) {
                ll res_left = evaluate(i, k);
                ll res_right = evaluate(k + 1, j);
                ll cost = (res_left + res_right) + mergeCost(i, j, k);
                ans = min(ans, cost);
            }
            dp[i][j] = ans;
        }
    }
 
    return dp[0][n-1];
}
 
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int row, col;
        cin >> row >> col;
        mats.emplace_back(row, col); 
    }
    //iterative version
    cout << solve() << '\n';
    //recursive version
    memset(dp, -1, sizeof dp);
    cout << solve(0, n - 1) << '\n';
}
