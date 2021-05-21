//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
#define PI 3.14159265
#define mod 1000000007
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
ll ncr(ll n,ll r){ ll ans=1;for(ll i=1;i<=r;i++) ans=(ans*(n-i+1))/i;return ans;}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,m;
        cin>>l>>m;
        string s;
        queue<int> left,right;
        ll x;
        for(int i=0;i<m;i++)
        {
            cin>>x>>s;
            if(s[0]=='l') left.push(x);
            else right.push(x);
        }
        ll ans=0;
        while(true)
        {
            ll sum=0;
            while(!left.empty())
            {
                x=left.front();
                if(sum+x<=l*100)
                {
                    sum=sum+x;
                    left.pop();
                }
                else
                break;
            }
            ++ans;
            if(left.empty()&&right.empty())
            break;
            sum=0;
            while(!right.empty())
            {
                x=right.front();
                if(sum+x<=l*100)
                {
                    sum=sum+x;
                    right.pop();
                }
                else
                break;
            }
            ++ans;
            if(left.empty()&&right.empty())
            break;
        }
        cout<<ans<<endl;
    }
}
