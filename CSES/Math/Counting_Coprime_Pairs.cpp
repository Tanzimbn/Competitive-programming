//...Bismillahir Rahmanir Rahim. . .

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// typedefs...
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

// constants...
const double PI = acos(-1);
const ll mod = 998244353; // 1000000007;
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
#define sz(x)      (int)x.size()
#define all(x)      begin(x), end(x)
#define si(a)       scanf("%d", &a)
#define sii(a, b)    scanf("%d%d", &a, &b)
#define ordered_set tree<ll,null_type,greater_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define iter_(i,n)    for (int i = 0; i < int(n); i++)
#define for_n(i, n)  for (int i = 1; i <= int(n); i++)
#define print_array(a) for(int i=0;i<n;i++)  cout<<a[i]<<" ";
#define rev(i,n)     for(int i=n;i>=0;i--)
#define itr          ::iterator
#define s_sort(s)    sort(s.begin(),s.end())
#define n_sort(a, n)    sort(a,a+n)
#define precise_impact cout<<setprecision(10)<<fixed;
#define endl         "\n"
// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b){ if(b==0){ return 1;} ll tm=bigmod(a,b/2); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n) {return modpow(n,mod-2);}
//int fact[100005];
//ll ncr_mod(ll n,ll r) {return (((fact[n]*inverse_mod(fact[r]))%mod)*inverse_mod(fact[n-r]))%mod;}
vector<int> p;
int pp[1005],mp[1000005];
void seive()
{
    p.PB(2);
    for(int i=3;i*i<=1000;i+=2)
    {
        if(pp[i]==0)
        {
            for(int j=i*i;j<=1000;j=j+2*i)
            pp[j]=1;
        }
    }
    for(int i=3;i<=1000;i+=2)
    if(pp[i]==0) p.PB(i);
}
int main()
{
    boost_;
    seive();
    ll n,x;
    cin>>n;
    ll ans=(n*(n-1))/2;
    while(n--)
    {
      cin>>x;
      vector<int> v;
      for(int i=0;p[i]*p[i]<=x&&i<p.size();i++)
      {
        if(x%p[i]==0)
        {
            v.PB(p[i]),x/=p[i];
            while(x%p[i]==0) x/=p[i];
        }
      }
      if(x>1) v.PB(x);
      // taken all prime
      // now inclusion-exclusion
      int m=v.size(),sum=0;
      for(int i=1;i<(1<<m);i++)
      {
        int num=1,temp=0;
        for(int j=0;j<m;j++)
        {
           if(i&(1<<j)) temp++,num=num*v[j];
        }
        if(temp%2) sum+=mp[num];
        else sum-=mp[num];
        mp[num]++;
      }
      ans-=sum;
    }
    cout<<ans<<endl;
}
