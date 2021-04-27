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
ll dp[1005][2005],n,m;
void next_mask(int mask,int i,int next,vector<int> &v)
{
     if(i==n)
     {
     	if((1<<n)==mask+1) v.push_back(next);
     	return;
     }
     if((mask&(1<<i)))
     {
     	next_mask(mask,i+1,next,v);
     	return;
     }
     if(i+1!=n)
     {
     	if(!(next&(1<<(i+1))))
     	next_mask(mask+(1<<i)+(1<<(i+1)),i+2,next,v);
     }
     next_mask(mask+(1<<i),i+1,next+(1<<i),v);
     return;
}
ll check(int col,int mask)
{//cout<<col<<mask<<endl;
    if(col==m+1)
    {
    	if(mask==0)return 1;
    	return 0;
    }
    if(dp[col][mask]!=-1) return dp[col][mask];
    ll sum=0;
    vector<int> v;
    next_mask(mask,0,0,v);
    for(int i=0;i<v.size();i++)
    sum=(sum+check(col+1,v[i]))%mod;
return dp[col][mask]=sum;
}
int main()
{
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<check(1,0);
}
