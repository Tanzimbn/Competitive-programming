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
ll a[100005],temp[5005][5005],b[5005][5005];
void dp(int l,int r)
{
    if(l==r)
    {
        temp[l][r]=a[l];
        return ;
    }
    if(temp[l][r]!=-1) return;
    dp(l+1,r);
    dp(l,r-1);
    temp[l][r]=max(b[l+1][r]-temp[l+1][r]+a[l],b[l][r-1]-temp[l][r-1]+a[r]);
    //cout<<l<<r<<temp[l][r]<<endl;
    return;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        ll sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            b[i][j]=sum;
        }
    }
    memset(temp,-1,sizeof(temp));
    dp(0,n-1);
    cout<<temp[0][n-1]<<endl;
}
int main()
{
    //fast();
    solve();
}
