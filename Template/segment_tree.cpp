ll seg[400005],a[100005],lazy[400005];
// can lazy be zero by default ,check question
// if we have multiple test case then check seg,a,lazy array 
// 0 index or 1 index for query and update

void build(int pos,int l,int r)
{
    lazy[pos]=0;
    if(l==r)
    {
        seg[pos]=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);
    seg[pos]=seg[2*pos]+seg[2*pos+1];
}
void lazy_update(int pos,int l,int r)
{
    seg[pos]+=(r-l+1)*lazy[pos];
    if(l!=r)
    {
        lazy[2*pos]+=lazy[pos];
        lazy[2*pos+1]+=lazy[pos];
    }
    lazy[pos]=0;
}
void update(int pos,int l,int r,int x,int y,ll val)
{
    if(lazy[pos]!=0) 
    lazy_update(pos,l,r);

    if(l>y||x>r) return;
    if(l>=x&&r<=y)
    {
        lazy[pos]+=val;
        lazy_update(pos,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(2*pos,l,mid,x,y,val);
    update(2*pos+1,mid+1,r,x,y,val);
    seg[pos]=seg[2*pos]+seg[2*pos+1];
}
ll query(int pos,int l,int r,int x,int y)
{
    if(lazy[pos]!=0)
    lazy_update(pos,l,r);

    if(l>y||x>r) return 0;
    if(l>=x&&r<=y) return seg[pos];
    int mid=(l+r)>>1;
    ll q1=query(2*pos,l,mid,x,y);
    ll q2=query(2*pos+1,mid+1,r,x,y);
    return q1+q2;
}
