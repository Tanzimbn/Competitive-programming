struct ncr_mod {
    ll N;
    vector<ll> fact, inv;
    ncr_mod(ll n) { 
        N = n; fact.assign(n+5, 0); inv.assign(n+5, 0); 
        fact[0] = 1;
        for(ll i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        inv[N] = inverse_mod(fact[N], mod);
        for(ll i = N - 1; i >= 0; i--) {
            inv[i] = (inv[i + 1] * (i + 1) ) % mod;
        }
    }
    ll find(ll n, ll r) {
        if(n < r || r < 0) return 0;
        ll temp = ( inv[r] * inv[n - r] ) % mod;
        return (temp * fact[n]) % mod;
    }
};
