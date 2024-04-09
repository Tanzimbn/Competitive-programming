vector<ll>basis;
bool basis_add(ll x)
{
    for(ll i:basis)
        x=min(x,x^i);
    if(x){
        basis.push_back(x);
        return true;
    }
    return false;
}
bool basis_check(ll x)
{
    for(ll i:basis)
        x=min(x,x^i);
    return x!=0;
}
