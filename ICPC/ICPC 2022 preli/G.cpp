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
#define endl '\n'

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}

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
            if(r - j > n - i) continue; // impossible case for remaining road and remaining node
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