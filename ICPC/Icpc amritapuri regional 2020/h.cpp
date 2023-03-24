#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// typedefs...
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

// constants...
const double PI = acos(-1);
const ll mod = 1000000007; // 998244353
const int MXS = 2e5+5;
const ll MXI = 1e9+5;
const ll MXL = 1e18+5;
const ll INF = 1e9+5;
const ll INFLL = 1e18+5;
const ll EPS = 1e-9;

// defines...
#define MP        make_pair
#define PB        push_back
#define fi         first
#define se         second
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}

int valid[505][505], n, a[505], b[505], pos[505];
ll div_dp[505][505];
ll divide(int x,int y) {
  if(x >= y) return 1;
  if(div_dp[x][y] != -1) return div_dp[x][y];
  ll ans = 0;
  for(int i = x; i <= y; i++) {
    if(valid[x][i]) {
      ll temp = (divide(x + 1, i) * divide(i + 1, y)) % mod;
      ans = (ans + temp) % mod;
    }
  }
  return div_dp[x][y] = ans;
}

void solve()
{   
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
      pos[b[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
      int mn = pos[a[i]], mx = pos[a[i]];
      for(int j = i; j <= n; j++) {
        div_dp[i][j] = -1;
        mn = min(mn, pos[a[j]]);
        mx = max(mx, pos[a[j]]);
        valid[i][j] = 0;
        if(b[mn] == a[i] && mx - mn == j - i) {
          valid[i][j] = 1;
        }
      }
    }
    cout << divide(2, n) << endl;
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