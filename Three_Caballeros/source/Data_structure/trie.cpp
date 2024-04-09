const int N=1e6+100;
int Trie[N][26],Nodes=1;
int cnt[cur_node];
 
int query(string st)
{
    int cur_node=1;
    for(auto i:st)
    {
        int ch=i-'a';
        if(Trie[cur_node][ch]==0)
            return 0;
        cur_node=Trie[cur_node][ch];
    }
    return cnt[cur_node];
}
 
void build_trie(string st)
{
    int cur_node=1;
    cnt[cur_node]++;
    for(auto i:st)
    {
        int ch=i-'a';
        if(Trie[cur_node][ch]==0)
            Trie[cur_node][ch]=++Nodes;
        cur_node=Trie[cur_node][ch];
        cnt[cur_node]++;
    }
}
