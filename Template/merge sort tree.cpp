const int N = 1e5 + 5;
vector<int>tree[5*N];
int A[N];
 // merge and query vary with problem
vector<int> merge(vector<int> &a, vector<int> &b) {
  vector<int> v;
  int i = 0, j = 0;
  for(; i < a.size() && j < b.size();) {
    if(a[i] < b[j]) {
      if(v.size() == 0 || v.back() < a[i])
      v.PB(a[i]);
      i++;
    }
    else {
      if(v.size() == 0 || v.back() < b[j])
      v.PB(b[j]);
      j++;
    }
  }
 
  while(i < a.size()) {
    if(v.size() == 0 || v.back() < a[i])
    v.PB(a[i]);
    i++;
  }
  while(j < b.size()) {
    if(v.size() == 0 || v.back() < b[j])
    v.PB(b[j]);
    j++;
  }
  return v;
}
 
void build_tree( int cur , int l , int r )
{
     tree[cur].clear();
     if( l==r )
     {
            tree[cur].push_back( A[l] );
            return ;
     }
     int mid = l+(r-l)/2;
     build_tree(2*cur , l , mid ); // Build left tree 
     build_tree(2*cur+1 , mid+1 , r ); // Build right tree
     tree[cur] = merge( tree[2*cur+1] , tree[2*cur+2] ); //Merging the two sorted arrays
}
int query(int cur, int l, int r, int x, int y, int val) {
    if(x <= l && r <= y) {
        int pos = lower_bound(tree[cur].begin(), tree[cur].end(), val) - tree[cur].begin();
        return (tree[cur].size() - pos);
    }
    if(r < x || l > y) return 0;
    int mid = (l + r) / 2;
    int q1 = query(2*cur , l , mid, x, y, val); 
    int q2 = query(2*cur+1 , mid+1 , r,x, y, val);
    return q1 + q2;
}
