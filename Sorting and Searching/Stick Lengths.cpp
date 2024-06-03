#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int n; cin >> n;
    ll a[n];
    ll ans = 0;
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    if(n%2 == 1){
        ll med = a[n/2];
        for(auto c:a){
            ans += abs(c-med);
        }
    }
    else{
        ll ans1=0,ans2=0;
        ll med1 = a[(n-1)/2],med2 = a[n/2];
        // cout<<med1<<" "<<med2<<endl;
        for(auto c:a){
            // cout<<c<<" ";
            ans1 += abs(c-med1);
            ans2 += abs(c-med2);
    
        }
        ans = min(ans1,ans2);
    }
    cout<<ans<<endl;
}