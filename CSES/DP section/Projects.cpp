//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
#define fi first
#define se second
#define PI 3.14159265
#define mod  1000000007
#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
///order_of_key find_by_order
const ll INFLL = 1e18;
const ll INF =1e9;
const ll EPS =1e-9;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
ll ncr(ll n,ll r){ ll ans=1;for(ll i=1;i<=r;i++) ans=(ans*(n-i+1))/i;return ans;}
ll dp[200005];
void solve()
{
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int> > v;
    for(int i=0;i<n;i++)
    {
        ll x,y,p;
        cin>>x>>y>>p;
        v.push_back({{y,x},p});
    }
    sort(v.begin(),v.end());
    vector<ll> endp;
    dp[0]=0;
    for(int i=0;i<v.size();i++)
    {
        ll temp=v[i].fi.se;
        temp=lower_bound(endp.begin(),endp.end(),temp)-endp.begin();
        endp.push_back(v[i].fi.fi);
        dp[i+1]=max(dp[i],dp[temp]+v[i].se);
    }
    cout<<dp[n]<<endl;
}
int main()
{
    fast();
    solve();
}
