struct Triplet
{
   int x,y,gcd;
};
 
Triplet extendedEuclid(int a, int b)
{
   if(b == 0){
       Triplet ans;
       ans.gcd = a;
       ans.x = 1;
       ans.y = 0;
       return ans;
   }
 
   Triplet next = extendedEuclid(b, a%b);
   Triplet ans;
   ans.gcd = next.gcd;
   ans.x = next.y;
   ans.y = next.x - (a/b)*next.y;
   return ans;
}

void solve()
{
    int n;
    cin>>n;
    ll a[2*n+5];
    for(int i=0;i<2*n;i+=2) cin>>a[i];
    if(n==1)
    {
        cout<<a[0]<<endl;return;
    }
    for(int i=0;i<=10000;i++)
    {
        // bp+cq=r
        ll r=a[2]-i*i*a[0]; 
        ll p=i+1;
        ll q=10001;
        Triplet ans=extendedEuclid(p,q);
        
        if(r%ans.gcd) continue;
        ll x=ans.x*(r/ans.gcd);
        int temp=0;
        for(int j=1;j<2*n;j++)
        {
            if(j%2)
            {
                a[j]=(i*a[j-1]+x)%10001;
            }
            else
            {
                if(a[j]!=(i*a[j-1]+x)%10001)
                {
                   temp=1;break;
                }
            }
        }
        if(temp==0) break;
    }
    for(int i=1;i<2*n;i+=2)
    cout<<a[i]<<endl;
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
