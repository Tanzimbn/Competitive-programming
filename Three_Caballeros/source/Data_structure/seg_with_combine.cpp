vector < node > t(8e5 + 1);
node combine(node a, node b) {
  node f;
  if (a.right <= b.left) {
 
    f.lefts = (a.lefts == a.siz) ? a.lefts + b.lefts : a.lefts;
    f.rights = (b.rights == b.siz) ? (a.rights + b.rights) : b.rights;
    f.sum = a.sum + b.sum - a.rights * (a.rights + 1) / 2 - b.lefts * (b.lefts + 1) / 2 + (a.rights + b.lefts) * (a.rights + b.lefts + 1) / 2;
  } else {
    f.lefts = a.lefts;
    f.rights = b.rights;
    f.sum = a.sum + b.sum;
  }
 
  f.right = b.right;
  f.left = a.left;
  f.siz = a.siz + b.siz;
  return f;
}
void build(int n, int b, int e, vector < int > & v) {
  if (b == e) {
    t[n].siz = t[n].sum = t[n].rights = t[n].lefts = 1;
    t[n].right = t[n].left = v[b];
 
  } else {
    build(2 * n, b, (b + e) / 2, v);
    build(2 * n + 1, (b + e) / 2 + 1, e, v);
    t[n] = combine(t[2 * n], t[2 * n + 1]);
 
  }
}
 
void update(int n, int b, int e, int i, int j, int val) {
  if (e < i or b > j)
    return;
  if (b >= i and e <= j) {
 
    t[n].right = t[n].left = val;
    return;
  }
  update(2 * n, b, (b + e) / 2, i, j, val);
  update(2 * n + 1, (b + e) / 2 + 1, e, i, j, val);
  t[n] = combine(t[2 * n], t[2 * n + 1]);
 
}
node get_sum(int n, int b, int e, int i, int j) {
 
  if (e < i or b > j) {
    node p;
    p.siz = p.sum = p.rights = p.lefts = 0;
    p.right = p.left = -1;
    return p;
  }
  if (b >= i and e <= j) {
    return t[n];
  }
  node p1 = get_sum(2 * n, b, (b + e) / 2, i, j);
  node p2 = get_sum(2 * n + 1, (b + e) / 2 + 1, e, i, j);
  if (p1.right == -1)
    return p2;
  if (p2.right == -1)
    return p1;
  return combine(p1, p2);
}
