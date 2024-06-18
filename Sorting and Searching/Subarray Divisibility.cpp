#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ll rem[n];
    for (int i = 0; i < n; i++)
    {
        rem[i] = 0;
    }
    ll sum = 0,ans = 0;
    rem[0] = 1;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        sum += a;
        ll rm;
        if(abs(sum)%n == 0) rm = 0;
        else if(sum > 0) rm = sum%n;
        else rm = n-abs(sum)%n;
        ans += rem[rm];
        // cout<<sum<<" "<<rem[rm]<<" "<<ans<<endl;
        rem[rm]++;
    }
    cout<<ans<<endl;
}