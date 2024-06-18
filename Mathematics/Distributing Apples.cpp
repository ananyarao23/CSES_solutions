#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
const ll mod = 1e9+7;
#define pl pair<ll,ll>
#define ppi pair<pl,ll>
#pragma GCC optimize("O3")

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

ll modInverse(ll A, ll M)
{
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return -1;
    else {
        ll res = (x % M + M) % M;
        return res;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll r,n;
    cin >> r >> n;
    ll num = 1,den = 1;
    --r;
    ll x = max(n,r);
    ll y = min(n,r);
    ll ans = 1;
    for (ll i = 1; i <= y; i++)
    {
        ans = (ans*(x+i)*modInverse(i,mod))%mod;
    }
    cout<<ans<<endl;
}