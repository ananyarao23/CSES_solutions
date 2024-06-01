#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define ln 1000000007

ll mypow(int n){
    if(n==0) return 1;
    if(n%2 == 0){
        ll ans = mypow(n/2);
        return (ans*ans)%ln;
    }
    else{
        ll ans = mypow((n-1)/2);
        // cout<<(n-1)/2<<" "<<ans<<endl;
        return (2*ans*ans)%ln;
    }
}
    
int main(){
    ll n; cin >> n;
    ll ans = mypow(n);
    cout<<ans<<endl;
}