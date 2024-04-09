const int mod = 998244353;
const int root = 15311432;
const int k = 1 << 23;

int root_1;
vector<int> rev;

ll bigmod(ll a, ll b, ll mod){
  a %= mod;
  ll ret = 1;
  while(b){
    if(b&1) ret = ret*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return ret;
}

void pre(int sz){
  root_1 = bigmod(root, mod-2, mod);
  if(rev.size()==sz)  return ;
  rev.resize(sz);
  rev[0]=0;
  int lg_n = __builtin_ctz(sz);
  for (int i = 1; i < sz; ++i)  rev[i] = (rev[i>>1] >> 1) | ((i&1)<<(lg_n-1));
}

void fft(vector<int> &a, bool inv){
  int n = a.size();

  for (int i = 1; i < n-1; ++i) if(i<rev[i])  swap(a[i], a[rev[i]]);

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = inv ? root_1 : root;
    for (int i = len; i < k; i <<= 1){
      wlen = 1ll*wlen*wlen%mod;
    }
    for (int st = 0; st < n; st += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int ev = a[st+j];
        int od = 1ll*a[st+j+len/2]*w%mod;
        a[st+j] = ev + od < mod ? ev + od : ev + od - mod;
        a[st+j+len/2] = ev - od >= 0 ? ev - od : ev - od + mod;
        w = 1ll * w * wlen % mod;
      }
    }
  }

  if (inv) {
    int n_1 = bigmod(n, mod-2, mod);
    for (int & x : a)
      x = 1ll*x*n_1%mod;
  }
}

vector<int> mul(vector<int> &a, vector<int> &b){
  int n = a.size(), m = b.size(), sz = 1;
  while (sz < n+m-1)  sz <<= 1;
  vector<int> x(sz), y(sz), z(sz);
  for (int i = 0; i < sz; ++i){
    x[i] = i<n? a[i]: 0;
    y[i] = i<m? b[i]: 0;
  }
  pre(sz);
  fft(x, 0);
  fft(y, 0);
  for (int i = 0; i < sz; ++i){
    z[i] = 1ll* x[i] * y[i] % mod;
  }
  fft(z, 1);
  z.resize(n+m-1);
  return z;
}