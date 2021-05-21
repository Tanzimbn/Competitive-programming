//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define PI 3.14159265
#define mod 998244353
const ll INFLL = 1e18;
const ll INF =1e10;

void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
ll ncr(ll n,ll r){ ll ans=1;for(ll i=1;i<=r;i++) ans=(ans*(n-i+1))/i;return ans;}
ll a[67][67][2];
ll dp(int desk,int safe,int pre)
{
    if(safe>desk||safe<0) return 0;
    if(a[desk][safe][pre]!=-1) return a[desk][safe][pre];
    if(desk==1) //last desk
    {
        if(pre==1&&safe<=1) return 1;
        else if(pre==0&&safe==0) return 2; //pre was unsafe so last will unsafe though it is open or close
        else return 0;
    }
    if(pre) a[desk][safe][pre]=dp(desk-1,safe,0)+dp(desk-1,safe-1,1);
    else a[desk][safe][pre]=dp(desk-1,safe,0)+dp(desk-1,safe,1);
    return a[desk][safe][pre];
}
int main()
{
    int n,m;
    memset(a,-1,sizeof(a));
    while(cin>>n>>m)
    {
        if(n<1) break;
        cout<<dp(n,m,1)<<endl;
        for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        a[i][j][1]=a[i][j][0]=-1;
    }
}
