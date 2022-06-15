#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFLL = 1e18+5;
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
ll n,dis[20][20],deg[20],dp[(1LL<<16)];
ll check(ll mask)
{
   if(mask==0) return 0;
   if(dp[mask]!=-1) return dp[mask];
   int pos;
   for(int i=1;i<=n;i++)
   {
      if((1LL<<i)&mask)
      {
         pos=i;break;
      }
   }
   ll ans=INFLL;
   for(int i=pos+1;i<=n;i++)
   {
      if(((1LL<<i)&mask)==0) continue;
      ll temp=check(mask-(1LL<<i)-(1LL<<pos));
      ans=min(ans,dis[pos][i]+temp);
   }
   return dp[mask]=ans;
}

void solve()
{
   int m;
   cin>>n;
   if(n==0) return;
   cin>>m;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++) 
      {
         dis[i][j]=INFLL;
         if(i==j) dis[i][j]=0;
      }
      deg[i]=0;
   }
   ll ans=0;
   while(m--)
   {
      ll x,y,c;
      cin>>x>>y>>c;
      dis[x][y]=min(dis[x][y],c);
      dis[y][x]=min(dis[y][x],c);
      deg[x]++,deg[y]++;
      ans+=c;
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
      {
         for(int k=1;k<=n;k++)
         {
            dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
         }
      }
   }
   ll mask=0;
   for(int i=1;i<=n;i++)
   {
      if(deg[i]%2) mask+=(1LL<<i);
   }
   memset(dp,-1,sizeof(dp));
   cout<<ans+check(mask)<<endl;
   solve();
}
int main()
{
    boost_;
    int t=1;
   // cin>>t;
   
    for(int i=1;i<=t;i++)
    {
       //cout<<"Case "<<i<<": ";
       solve();
    }
}
