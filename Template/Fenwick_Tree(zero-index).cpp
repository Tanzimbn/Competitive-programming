struct Fenwick{
 
     int n;
     vector<int> fen;  // vector element max value check
     Fenwick(int n) { this->n=n;fen.assign(n+5,0);}
     int query(int pos)
     {
        int ans=0;
        while(pos>=0)
        {
            ans=ans+fen[pos];  // operation check
            pos=(pos&(pos+1))-1;
        }
        return ans;
     }
     void update(int pos,int val)
     {
        while(pos<=n)
        {
           fen[pos]+=val;  // operation check
           pos|=(pos+1);
        }
     }
};
