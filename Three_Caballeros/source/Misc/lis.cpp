int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = INT_MAX;// be careful here
    vector<int> d(n+1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j]) // for non-decreasing all < will replaced with <=
            d[j] = a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}}
