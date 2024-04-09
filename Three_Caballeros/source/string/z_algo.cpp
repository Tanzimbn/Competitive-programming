//0 indexed
int z[500003];
void z_algo(string s)
{
    int i,l=0,r=0,x=s.length();
    z[0]=x;
    for(i=1;i<x;i++)
    {
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        else
            z[i]=0;
        while(i+z[i]<x&s[i+z[i]]==s[z[i]])++z[i];
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
}
