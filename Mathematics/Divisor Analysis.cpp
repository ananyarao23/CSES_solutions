#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
const ll mod = 1000000007;

ll pow_mod(ll p,ll c,ll m){
    if(c == 1) return p%m;
    ll ans = pow_mod(p,c/2,m);
    if(c%2 == 1){
        return (p*ans*ans)%m;
    }
    return (ans*ans)%m;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll count = 1,sum = 1,prod = 1;
    ll n; cin >> n;
    pl fact[n];
    for (ll i = 0; i < n; i++)
    {
        ll p,c; cin >> p >> c;
        fact[i].first = p;
        fact[i].second = c;
        count = (count*(c+1))%mod;
        ll ex = pow_mod(p,c,mod);
        sum = (sum*(ex*p-1)/(p-1))%mod;
    }
    for (ll i = 0; i < n; i++)
    {
        ll p = fact[i].first,c = fact[i].second;
        ll ex = pow_mod(p,((c*(c+1))/2)*(count/(c+1)),mod);
        prod = (prod*ex)%mod;
    }
    cout << count << " " << sum << " " << prod <<endl;
}