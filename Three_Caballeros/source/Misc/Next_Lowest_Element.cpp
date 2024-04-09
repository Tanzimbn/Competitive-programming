void next_lowest(ll int a[],ll int b[],ll int n)
{
    stack<pa>s;
    s.push({-1,n+1});//first of pair will be min(ai)-1
    for(int i=n;i>=1;i--)
    {
        while(s.top().ff>=a[i])s.pop();
        b[i]=s.top().ss;
        s.push({a[i],i});
    }
}
