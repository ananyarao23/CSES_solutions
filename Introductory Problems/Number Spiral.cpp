#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int t; cin >> t;
    while (t--)
    {
        ll x,y;
        cin >> x >> y;
        ll e = max(x,y);
        // if e is even then numbering will start from top right
        ll ans;
        if(e%2 == 0){
            ans = (e-1)*(e-1) + x + e-y;
        }
        else ans = (e-1)*(e-1) + y + e-x;
        cout<<ans<<endl;
        // if e is odd then numbering will start from bottom left
    }
    
}