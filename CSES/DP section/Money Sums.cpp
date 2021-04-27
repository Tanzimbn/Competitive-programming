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
#define mod  998244353
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
int dp[100005];
int main()
{
    int n;
    cin>>n;
    int sum=0,a[n+5],num=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=sum;j>=a[i];j--)
        {
            if(dp[j-a[i]]) dp[j]=1;
        }
    }
    vector<int> v;
    for(int i=1;i<=sum;i++)
    {
        if(dp[i])
        {
            ++num,v.push_back(i);
        }
    }
    cout<<num<<endl;
    for(int i=0;i<num;i++) cout<<v[i]<<" ";
    cout<<endl;
}
