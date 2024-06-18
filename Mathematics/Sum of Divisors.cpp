#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
const ll md = 1000000007;
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans = (ans + n-n%i)%md;
    }
    cout<<ans<<endl;
}