struct DSUrollback {
    int n, cmp, cur = -1;
    vector<int> par, rank, cmpsz;
    vector<pii> stack;
 
    void init(int n) {
        this->n = cmp = n;
        par.resize(n + 5), rank.resize(n + 5), cmpsz.resize(n + 5);
        for(int i = 0; i <= n; i++)
        par[i]=i, rank[i] = 1;
    }
    int find(int x) {
        if(x == par[x]) return x;
        return find(par[x]);
    }
    bool merge(int x, int y) {
        int xroot = find(x), yroot = find(y);
        if(xroot != yroot) {
            if(rank[xroot] < rank[yroot]) swap(xroot, yroot);
            par[yroot] = xroot;
            rank[xroot] += rank[yroot];
            stack.PB({yroot, xroot});
            cur++;
            cmpsz[cur] = cmp;
            cmp--;
            return true;
        }
        else {
            stack.PB({-1, -1});
            return false;
        }
    }
    void rollback() {
        if(stack.back().fi == -1) {
            stack.pop_back(); return; // no change in last operation
        }
        par[stack.back().fi] = stack.back().fi;
        rank[stack.back().se] -= rank[stack.back().fi];
        cmp = cmpsz[cur];
        cur--;
        stack.pop_back();
    }
};
