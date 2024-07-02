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
const ll mod =1000000007 ; // 998244353
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
//ll fact[2000005];
//ll ncr_mod(ll n,ll r) {return (((fact[n]*inverse_mod(fact[r]))%mod)*inverse_mod(fact[n-r]))%mod;}

void solve()
{
    ll n;
    cin >> n;
        
    ll a[n];
    ll mx = -INFLL, len = 1;

    ll temp = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        temp += a[i];
        cnt++;
        if(temp > mx) {
            mx = temp, len = cnt;
        }
        if(temp <= 0) {
            temp = 0, cnt = 0;
        }
    }

    vector<vector<int> > tot;
    vector<int> v;
    temp = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        temp += a[i];
        cnt++;
        v.PB(a[i]);

        if(temp == mx && len == cnt) {
            sort(v.begin(), v.end());
            tot.PB(v);
            v.clear();
        }
        if(temp <= 0) {
            temp = 0, cnt = 0;
            v.clear();
        }
    } 
    sort(tot.begin(), tot.end());

    // for(int i = 0; i < tot.size(); i++) {
    //     for(auto it : tot[i]) cout << it << " ";
    //     cout << endl;
    // }
    // cout << endl;
    temp = 1, cnt = 1;
    for(int i = 1; i < tot.size(); i++) {
        int yes = 1;
        for(int j = 0; j < len; j++) {
            if(tot[i][j] != tot[i - 1][j]) yes = 0;
        }
        if(yes) temp++;
        else temp = 1;
        cnt = max(cnt, temp);
    }
    cout << cnt * len << endl;
}
int main()
{
    boost_;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       cout<<"Case "<<i<<": ";
       solve();
    }
}
