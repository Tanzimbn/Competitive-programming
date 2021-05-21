//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
#define PI 3.14159265
#define mod 1000000007
const ll INFLL = 1e18;
const ll INF =1e9;
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
ll ncr(ll n,ll r){ ll ans=1;for(ll i=1;i<=r;i++) ans=(ans*(n-i+1))/i;return ans;}
int n,s,t,m;
void dijsktra(vector<int>dijsktra_v[],vector<int>cost[])
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> dis(n+1,INF);
    pq.push({0,s}); // distance from source node,node number
    dis[s]=0;
    while(!pq.empty())
    {
        int num=pq.top().ss;
        int num_d=pq.top().ff;
        pq.pop();
        if(num_d!=dis[num]) continue;
        for(int i=0;i<dijsktra_v[num].size();i++)
        {
            if(num_d+cost[num][i]<dis[dijsktra_v[num][i]])
            {
                dis[dijsktra_v[num][i]]=num_d+cost[num][i];
                pq.push({dis[dijsktra_v[num][i]],dijsktra_v[num][i]});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]<=t)++ans;
    }
    cout<<ans<<endl;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {

        cin>>n>>s>>t>>m;
        int x,y,w;
        vector<int> v[n+5],cost[n+5];
        while(m--)
        {
            cin>>x>>y>>w;
            v[y].push_back(x);
            cost[y].push_back(w);
        }
        dijsktra(v,cost);
        if(test>0) cout<<"\n";
    }
}
