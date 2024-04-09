struct MinQ
{
    int window;
    deque<pair<int,int> >dq;
    MinQ(int x)
    {
        window=x;
    }
    void push(int idx,int x)
    {
        while(!dq.empty() && dq.back().first>=x)dq.pop_back();
        dq.
        push_back(make_pair(x,idx));
    }
    int qry(int idx)
    {
        while(idx-dq.front().second>=window)dq.
            pop_front();
        return dq.front().first;
    }
};
/* MinQ a(x);x=window size
a.push(i,x);inserting x at idx=i
i must be sequentiallay added;//1 2 3 like this
a.qry(i)=min value in range(i-window+1,i);
if(a.dq.size()==k)range(i-window+1,i) e sob already sorted
,size neyar age pop korte qry koro
vector<MinQ>a(M,window);Can be used like this
*/
