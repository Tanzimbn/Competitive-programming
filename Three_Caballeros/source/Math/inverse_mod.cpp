//precompute modular inverse for every number in  [1, m-1]  in  O(m) .
int m=500;
int inv[m]; 
inv[1] = 1;
for(int a = 2; a < m; ++a)
    inv[a] = m - (long long)(m/a) *
 inv[m%a] % m;
