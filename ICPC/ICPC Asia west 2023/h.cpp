#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define PB        push_back
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  struct node {
    int val, sz, prior, lazy, sum, mx, mn, repl;
    pair<int,int> frw_hash;
    pair<int,int> rev_hash;
    bool repl_flag, rev;
    node *l, *r, *par;
    node() {
      prior = 0;
      l = NULL;
      r = NULL;
      par = NULL;
      frw_hash = {0 , 0};
      rev_hash = {0 , 0};
    }
    node(int _val) {
      val = _val;
      sz = 1;
      prior = rnd();
      l = NULL;
      r = NULL;
      par = NULL;
      frw_hash = {_val , _val};
      rev_hash = {_val , _val};
    }
  };
typedef node* pnode;
struct treap {
  //This is an implicit treap which investigates here on an array
  pnode root;
  map<int, pnode> position;//positions of all the values
  //clearing the treap
  void clear() {
    root = NULL;
    position.clear();
  }

  treap() {
    clear();
  }

  int size(pnode t) {
    return t ? t->sz : 0;
  }
  void update_size(pnode &t) {
    if(t) t->sz = size(t->l) + size(t->r) + 1;
  }

  void update_parent(pnode &t) {
    if(!t) return;
    if(t->l) t->l->par = t;
    if(t->r) t->r->par = t;
  }
  //split node t in l and r by key k
  //so first k+1 elements(0,1,2,...k) of the array from node t
  //will be split in left node and rest will be in right node
  void split(pnode t, pnode &l, pnode &r, int k, int add = 0) {
    if(t == NULL) {
      l = NULL;
      r = NULL;
      return;
    }
    int idx = add + size(t->l);
    if(t->l) t->l->par = NULL;
    if(t->r) t->r->par = NULL; 
    if(idx <= k)
      split(t->r, t->r, r, k, idx + 1), l = t;
    else
      split(t->l, l, t->l, k, add), r = t;

    update_parent(t);
    update_size(t);
    // operation(t);
  }
  //merge node l with r in t
  void merge(pnode &t, pnode l, pnode r) {
    if(!l) {
      t = r;
      return;
    }
    if(!r) {
      t = l;
      return;
    }

    if(l->prior > r->prior)
      merge(l->r, l->r, r), t = l;
    else
      merge(r->l, l, r->l), t = r;

    update_parent(t);
    update_size(t);
    // operation(t);
  }
  int get_index(pnode u,int cpos = 0, int lft = 0){
        if(!u) return cpos;
        if(!lft) cpos += 1 + size(u->l);
        pnode p = u->par;
        if(!p) return cpos;
        if(u == p->r) return get_index(p, cpos, 0);
        else return get_index(p, cpos, 1);

    }
  //returns size of the treap
  int size() {
    return size(root);
  }
  //inorder traversal to get indexes chronologically
  void inorder(pnode cur) {
    if(cur == NULL) return;
    // operation(cur);
    inorder(cur->l);
    // cout << cur->
    cout << cur->val << " ";
    inorder(cur->r);
  }
  //print current array values serially
  void print_array() {
//      for(int i=0;i<size();i++) cout<<get_val(i)<<' ';
//      cout<<nl;
    inorder(root);
    // cout << endl;
  }
  pnode get_par(pnode u){
    if (!u) return NULL;
    if(!u->par) return u->par;
    pnode p = u->par;
    if(p->l == u || p->r == u) return p;
    return NULL;
  }
    pnode get_root(pnode u){
        if(get_par(u)) return get_root(u->par);
        return u;
    }
};

treap tr;
void rearrange(pnode x) {
    int pos = tr.get_index(x);
    pnode l, r, rt = tr.get_root(x);
    tr.split(rt, l, r, pos - 2);
    tr.merge(rt, r, l);
}

void solve()
{
   int n, q;
   cin >> n >> q;

   int c[n + 1];
   pnode ar[n + 1];
   for(int i = 1; i <= n; i++) {
        ar[i] = new node(i);
        cin >> c[i];
   }

   int tot = 0, vis[n + 1] = {0};
   for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        tot++;
        vector<int> v;
        int x = i;
        while(vis[x] == 0) {
            v.PB(x);
            vis[x] = 1;
            x = c[x];
        }
        for(int i = 1; i < v.size(); i++) {
            pnode temp = tr.get_root(ar[v[i - 1]]);
            tr.merge(temp, temp, tr.get_root(ar[v[i]]));
        }
   }

   int u[q], v[q];
    for(int i = 0; i < q; i++) cin >> u[i];
    for(int i = 0; i < q; i++) cin >> v[i];

    int ans = 0;
    for(int i = 0; i < q; i++) {
        int x = (u[i] ^ ans);
        int y = (v[i] ^ ans);

        pnode rootx = tr.get_root(ar[x]);
        pnode rooty = tr.get_root(ar[y]);

        if(rootx == rooty) {
            tot++;
            rearrange(ar[x]);
            int posy = tr.get_index(ar[y]);
            pnode temp, temp1;
            tr.split(rootx, rootx, temp, posy - 1);
            tr.split(rootx, rootx, temp1, 0);
            tr.merge(rootx, rootx, temp);
        }
        else {
            tot--;
            rearrange(ar[x]);
            rearrange(ar[y]);
            pnode l1, l2, r1, r2;
            tr.split(rootx, l1, r1, 0);
            tr.split(rooty, l2, r2, 0);
            tr.merge(rootx, l1, r2);
            tr.merge(rootx, rootx, l2);
            tr.merge(rootx, rootx, r1);
        }

        cout << tot << " ";
        ans = tot;
    }
    cout << endl;

}
int main()
{
    boost_;
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout<<"Case "<<i<<": ";
       solve();
    }
}