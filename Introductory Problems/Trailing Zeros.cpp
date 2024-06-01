#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

ll factor(ll n, ll f){ 
    // returns largest power of f such that f^ans <= n
    ll ans = (log(n)/log(f));
    return ans;
}
    
int main(){
    ll n; cin >> n;
    ll n2=0,n5=0;
    ll x1 = factor(n,2);
    ll j=1;
    for (ll i = 2; j <= x1; i = i*2)
    {
        for (ll k = 1; i*k <= n; k += 2)
        {
            n2 += j;
        }
        j++;
    }
    ll x2 = factor(n,5);
    j=1;
    for (ll i = 5; j <= x2; i = i*5)
    {
        for (ll k = 1; i*k <= n; k += 1)
        {
            if(k%5 == 0) continue;
            n5 += j;
        }
        j++;
    }
    cout<<min(n2,n5)<<endl;
}