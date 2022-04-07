
void solve()
{
    ll p,q,r,s;
    while(cin>>p>>q>>r>>s)
    {
        vector<ll> up,dw;
        for(ll i=p-q+1;i<=p;i++) up.PB(i);
        for(ll i=1;i<=s;i++) up.PB(i);
        for(ll i=1;i<=q;i++) dw.PB(i);
        for(ll i=r-s+1;i<=r;i++) dw.PB(i);
        ll i=0,j=0;
    double ans=1;
    while(i<up.size()&&j<dw.size())
    {
        if(ans<1e10)
        {
            ans*=up[i];
            ++i;
        }
        else
        {
            ans/=dw[j];
            ++j;
        }
    }
    for(;i<up.size();i++) ans*=up[i];
    for(;j<dw.size();j++) ans/=dw[j];
    cout<<setprecision(5)<<fixed<<ans<<endl;
    }

}
int main()
{
    
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
       //cout<<"Case #"<<i<<": ";
       solve();
    }
}

