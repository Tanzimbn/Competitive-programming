struct seg_tree{
    vector<int>t,lazy,marked;
    int n;
    void init(int n)
    {
        this->n=n;
        t.resize(4*n+1);
        lazy.resize(4*n+1);
        marked.assign(4*n+1,0);
       // build(1,0,n-1);
    }
    void build(int n,int b,int e)
    {
        if(b==e)
        {
        t[n]=0;
 
 
        }
        else
        {
            build(2*n,b,(b+e)/2);
            build(2*n+1,(b+e)/2+1,e);
            t[n]=t[2*n]+t[2*n+1];
 
        }
    }
    void push(int n,int b,int e)
    {
 
        if(marked[n])
        {
            marked[2*n]=marked[2*n+1]=1;
            marked[n]=0;
            lazy[2*n]+=lazy[n];
            lazy[2*n+1]+=lazy[n];
            int mid=(b+e)/2;
            t[2*n]+=lazy[n]*(mid-b+1);
            t[2*n+1]+=lazy[n]*(e-mid);
            lazy[n]=0;
        }
    }
    void update(int i,int j,int val)
    {
        update(1,0,n-1,i,j,val);
    }
    void update(int n,int b,int e,int i,int j,int val)
    {
        if(e<i or b>j)
            return;
        if(b>=i and e<=j)
        {
            lazy[n]+=val;
            t[n]+=val*(e-b+1);
            marked[n]=1;
            return;
        }
        push(n,b,e);
        update(2*n,b,(b+e)/2,i,j,val);
        update(2*n+1,(b+e)/2+1,e,i,j,val);
        t[n]=t[2*n]+t[2*n+1];
 
    }
    int get_sum(int i,int j)
    {
        return get_sum(1,0,n-1,i,j);
    }
    int get_sum(int n,int b,int e,int i,int j)
    {
 
 
        if(e<i or b>j)
        {
 
            return 0;
        }
        if(b>=i and e<=j)
        {
 
 
            return t[n];
        }
        push(n,b,e);
        int p1=get_sum(2*n,b,(b+e)/2,i,j);
        int p2=get_sum(2*n+1,(b+e)/2+1,e,i,j);
 
        return p1+p2;
    }
};
struct node{
    int rights,lefts,sum,siz,right,left;
};