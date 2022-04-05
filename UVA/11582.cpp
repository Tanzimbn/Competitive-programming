ull f[1000500];
ull check(ull a,ull b,ull m)
{
   if(b==0) return 1;
   ull ans=check(a,b/2,m);
   ans=(ans*ans)%m;
   if(b%2==1) ans=(ans*(a%m))%m;
   return ans;
}
void solve()
{
   ull a,b,n;
   cin>>a>>b>>n;
   f[0]=0,f[1]=1%n;
   ull m;
   for(int i=2;;i++)
   {
      f[i]=(f[i-1]+f[i-2])%n;
      if(f[i]==f[1]&&f[i-1]==f[0])
      {
         m=i-1;break;
      }
   }
   
   m=check(a,b,m);
   cout<<f[m]<<endl;
}
int main()
{

    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       //cout<<"Case "<<i<<": ";
       solve();
    }
}

