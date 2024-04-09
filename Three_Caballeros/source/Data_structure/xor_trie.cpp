int a[100006];
struct node{
    int mark;
    node *nxt[2];
    node()
    {
        mark=0;
        for(int i=0;i<2;i++)
            nxt[i]=NULL;
    }
 
}*root;
void insert(int n)
{
    node* cur=root;
    for(int i=31;i>=0;i--)
    {
        int id=(n>>i)&1;
        if(cur->nxt[id]==NULL)
            cur->nxt[id]=new node();
        cur=cur->nxt[id];
    }
    cur->mark=n;
}
int maxsearch(int n)
{
    node* cur=root;
    for(int i=31;i>=0;i--)
    {
        int x=(n>>i)&1;
        if(cur->nxt[1-x]!=NULL)
               cur=cur->nxt[1-x];
        else
            cur=cur->nxt[x];
    }
    return cur->mark^n;
}
int minsearch(int n)
{
    node* cur=root;
    for(int i=31;i>=0;i--)
    {
        int x=(n>>i)&1;
        if(cur->nxt[x]!=NULL)
               cur=cur->nxt[x];
        else
            cur=cur->nxt[1-x];
    }
    return cur->mark^n;
}
void del(node *cur)
{
    for(int i=0;i<2;i++)
    {
        if(cur->nxt[i])
            del(cur->nxt[i]);
    }
    delete(cur);
}
