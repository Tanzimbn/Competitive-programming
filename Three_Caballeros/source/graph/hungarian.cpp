// Given the cost matrix "vector<vector<int>> A {...};"
// Elements are 1 indexed
// If the dimensions of A are n by m then n <= m
// Can handle negative cost
// Finds minimum cost but can be used to find to find
maximum by multiplying each cost by - 1
// Find the maximum matching
"vector<pair<int,int>>result;"
with all pairs
// As well as total cost "int C;" with the minimum
assignment cost.
// Complexity: O(n^2 m)
LL Hungarian(int n, int m, vector < vector < LL > > A,
  vector < pair < int, int >> & result) {
  LL inf = 1e18;
  vector < LL > u(n + 1), v(m + 1), p(m + 1), way(m + 1);
  for (int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    vector < LL > minv(m + 1, inf);
    vector < char > used(m + 1, false);
    do {
      used[j0] = true;
      LL i0 = p[j0], delta = inf, j1;
      for (int j = 1; j <= m; ++j) {
        if (!used[j]) {
          LL cur = A[i0][j] - u[i0] - v[j];
          if (cur < minv[j])
            minv[j] = cur,
            way[j] = j0;
          if (minv[j] < delta)
            delta = minv[j],
            j1 = j;
        }
      }
      for (int j = 0; j <= m; ++j) {
        if (used[j])
          u[p[j]] += delta, v[j] -=
          delta;
        else
          minv[j] -= delta;
      }
      j0 = j1;
    }
    while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    }
    while (j0);
  }
  for (int i = 1; i <= m; ++i) {
    result.push_back(make_pair(p[i], i));
  }
  LL C = -v[0];
  return C;
}
