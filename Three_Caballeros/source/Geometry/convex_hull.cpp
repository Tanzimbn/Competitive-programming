vector < point > ConvexHull(ll n,
  point ara[]) {
  ll i, j, k;
  vector < point > cnvx(2 * n);
  sort(ara, ara + n);
  for (i = 0, k = 0; i < n; ++i) {
    while (k >= 2 && direction(cnvx[k - 2], cnvx[k - 1], ara[i]) <= 0)
      k--;
    cnvx[k++] = ara[i];
  }
  for (i = n - 2, j = k + 1; i >= 0; --i) {
    while (k >= j && direction(cnvx[k - 2], cnvx[k - 1], ara[i]) <= 0)
      k--;
    cnvx[k++] = ara[i];
  }
  cnvx.resize(k - 1);
  return cnvx;
}
