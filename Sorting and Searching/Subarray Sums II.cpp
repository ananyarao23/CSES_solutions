#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x;
    cin >> n >> x;
    unordered_map<ll,ll> pref_freq;
    ll sum = 0;
    ll ans = 0;
    pref_freq[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        ll a; cin >> a;
        sum += a;
        // cout<<sum<<" ";
        ans += pref_freq[sum-x];
        pref_freq[sum]++;
    }
    cout<<endl;
    cout<<ans<<endl;
}