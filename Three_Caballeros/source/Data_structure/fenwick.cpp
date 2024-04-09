template<class T=long long>
struct FenwickTree {
    vector<T> bit;  // binary indexed tree
    int n;
    int logm;
 
    FenwickTree(int n) { // 0-index & size n-1
        this->n = n;
        bit.assign(n, 0);
        logm=0;
        while((1<<logm)<=n)
            logm++;
        logm--;
    }
    FenwickTree(vector<T> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    } 
    T sum(int r) {       //must
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    void refresh()     //optional
    {
        for(int &i:bit)
            i=0;
        return ;
    }
    T sum(int l, int r) {  // must
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {  //must
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    int bsearch(int v)        //optional
    {                         // searching prefix equal v
 
        int pos=0;
        int sum=0;
 
        for(int i=logm;i>=0;i--)
        {
            if(pos+(1<<i)-1<n and sum+bit[pos+(1<<i)-1]<=v)
            {
                sum+=bit[pos+(1<<i)-1];
                pos+=(1<<i);
            }
        }
        return pos;
    }
    //    FenwickTree<long long> f(100);
    //    f.add(10,4);
    //    cout<<f.sum(100,100) <<endl;
 };
