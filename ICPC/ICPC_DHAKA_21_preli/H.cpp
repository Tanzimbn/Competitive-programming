#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl '\n'

int seg[2][26][800005], lazy[2][800005];
string a[2];
void build(int pos,int l,int r, int typ)
{   
    if(l > r) return;
    lazy[typ][pos] = -1;
    if(l == r)
    {
        for(int i = 0; i < 26; i++) {
            seg[typ][i][pos] = ((a[typ][l - 1] - 'a') == i);
        }
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * pos, l, mid, typ);
    build(2 * pos + 1, mid + 1, r, typ);
    for(int i = 0; i < 26; i++)
    seg[typ][i][pos] = seg[typ][i][2 * pos] + seg[typ][i][2 * pos + 1];
}
void lazy_update(int pos, int l, int r, int typ) {
    for(int i = 0; i < 26; i++)
    seg[typ][i][pos] = 0;
    seg[typ][lazy[typ][pos]][pos] = (r - l + 1);
    if(l != r) {
        lazy[typ][2*pos] = lazy[typ][2*pos+1] = lazy[typ][pos];
    }
    lazy[typ][pos] = -1;
}
void update(int pos,int l,int r,int x,int y,int val,int typ)
{
    if(lazy[typ][pos] != -1) 
    lazy_update(pos, l, r, typ);

    if(l>y||x>r||r<l) return;
    if(l>=x&&r<=y)
    {
        lazy[typ][pos] = val;
        lazy_update(pos, l, r, typ);
        lazy[typ][pos] = -1;
        return;
    }
    int mid=(l+r)/2;
    update(2*pos,l, mid, x, y, val, typ);
    update(2*pos+1, mid+1, r, x, y, val, typ);
    for(int i = 0; i < 26; i++)
    seg[typ][i][pos] = seg[typ][i][2 * pos] + seg[typ][i][2 * pos + 1];
}
ll ans[2][30];
void query(int pos,int l,int r,int x, int y,int typ)
{
    if(lazy[typ][pos] != -1) 
    lazy_update(pos, l, r, typ);
    
    if(l>y||x>r||l>r) return;
    if(l>=x&&r<=y) {
        for(int i = 0; i < 26; i++)
        ans[typ][i] += seg[typ][i][pos];
        return;
    }
    int mid=(l+r)/2;
    query(2 * pos, l,mid, x, y, typ);
    query(2*pos + 1, mid + 1, r, x, y, typ);
}
void solve()
{   
    cin >> a[0] >> a[1];
    int n = a[0].size(), m = a[1].size();
    build(1, 1, n, 0);
    build(1, 1, m, 1);
    int q;
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(x > y) swap(x, y);
        if(t == 1) {
            char c;
            cin >> c;
            update(1, 1, n, x, y, (c - 'a'), 0);
        }
        else if(t == 2) {
            char c;
            cin >> c;
            update(1, 1, m, x, y, (c - 'a'), 1);
            
        }
        else if(t == 3){
            int  X, Y;
            cin >> X >> Y;
            if(X > Y) swap(X, Y);
            ll tot = (1LL * (y - x + 2) * (Y - X + 2));
            for(int i = 0; i < 26; i++)
            ans[0][i] = ans[1][i] = 0;
            query(1, 1, n, x, y, 0);
            query(1, 1, m, X, Y, 1);
            for(int i = 0; i < 26; i++) {
                tot -= ans[0][i] * ans[1][i];
            }
            cout << tot << '\n';
        }
    }
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