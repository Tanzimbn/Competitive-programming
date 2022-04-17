
vector<int> v[30];
pii check(int pos,int n)
{
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<v[i].size();j++)
     {
        if(v[i][j]==pos)
        return {i,j};
     }
   }
}
void bad(int pos,int h)
{
   for(int i=h+1;i<v[pos].size();i++)
   {
     int temp=v[pos][i];
     v[temp].PB(temp);
   }
   v[pos].erase(v[pos].begin()+h+1,v[pos].end());
}
void move(int pos,int h,int dis)
{
    for(int i=h;i<v[pos].size();i++)
    {
      int temp=v[pos][i];
      v[dis].PB(temp);
    }
    v[pos].erase(v[pos].begin()+h,v[pos].end());
}
void solve()
{
   int n;
   cin>>n;
   string s,t;
   int x,y;
   for(int i=0;i<n;i++) v[i].PB(i);
   while(cin>>s)
   {
     if(s=="quit") break;
     cin>>x>>t>>y;
     pii a=check(x,n);
     pii b=check(y,n);
     if(a.fi==b.fi) continue;
     if(t=="onto")
     {
        bad(b.fi,b.se);
     }
     if(s=="move")
     {
        bad(a.fi,a.se);
     }
     move(a.fi,a.se,b.fi);
   }
   for(int i=0;i<n;i++)
   {
     cout<<i<<":";
     for(int j=0;j<v[i].size();j++) cout<<" "<<v[i][j];
     cout<<endl;
   }
   
}
int main()
{

    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++)
    {
       //cout<<"Case "<<i<<":\n";
       solve();
    }
}

