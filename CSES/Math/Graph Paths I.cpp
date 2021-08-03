vector< vl > matrix_multi(vector< vl > a,vector< vl > b,int n)  
{
    vector<vl> ans (n+5,vl(n+5) );
    for(int i=0;i<n;i++)
          {
            for(int j=0;j<n;j++)
            {
                ll sum=0;
                for(int k=0;k<n;k++)
                {
                   sum=(sum+a[i][k]*b[k][j])%mod;
                }
                ans[i][j]=sum;
            }
          }
    return ans;
}
int main()
{

    int n,m,k;
    cin>>n>>m>>k;
    vector<vl> v (n+5,vl(n+5) ), ans(n+5, vl(n+5) );
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        --x,--y;
        v[n-1-y][n-1-x]++;
    }
    for(int i=0;i<=n;i++) ans[i][i]=1;
    
    while(k)
    {
        if(k%2)
        {
            ans=matrix_mul(ans,v,n);
        }
        k/=2;
        v=matrix_mul(v,v,n);
    }
    cout<<ans[0][n-1]<<endl;
}
