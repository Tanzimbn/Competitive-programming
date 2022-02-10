long long n,k,table[22][100005],a[100005]; // k=log(n) , table[maxlog][maxn]
long long func(long long a,long long b)
{
    return min(a,b);  // operation between two consecutive index 
} 
void build()
{
    for(int i=0;i<n;i++) table[0][i]=a[i];
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j+(1<<i)<=n;j++)
        {
            table[i][j]=func(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }
    }
}
long long query(int l,int r)
{
    long long ans=INT_MAX; // value depends on type of operation
    for(int j=k;j>=0;j--)
    {
        if(l+(1<<j)-1<=r)
        {
            ans=func(ans,table[j][l]);
            l+=(1<<j);
        }
    }
    return ans;
}
void linear_query(int q) // if idempotent function f(a,a)=a
{
    int lg[n+5],l,r; // check n
    lg[1]=0;
    for(int i=2;i<=n;i++) // check n
    {
        lg[i]=lg[i/2]+1;
    }
    while(q--)
    {
        cin>>l>>r;
        long long temp=lg[r-l+1];
        long long ans=func(table[temp][l],table[temp][r-(1<<temp)+1]);
        cout<<ans<<endl;
    }
}
