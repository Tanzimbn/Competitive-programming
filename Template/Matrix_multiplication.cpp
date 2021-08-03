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