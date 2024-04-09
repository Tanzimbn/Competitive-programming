int phi(int n)
{
    int result,i,j,k;
    result=n;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n=n/i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
