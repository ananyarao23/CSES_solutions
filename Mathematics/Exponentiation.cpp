#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
const ll ld = 1000000009;

ll myexp(ll a,ll b){
    if(a == 0){
        if(b == 0) return 1;
        return 0;
    }
    if(a == 1) return 1;
    if(b == 0) return 1;
    if(b%2 == 0){
        ll ans = myexp(a,b/2);
        return (ans*ans)%ld;
    }
    ll ans = myexp(a,b/2);
    return (a*ans*ans)%ld;
}

void test_case(){
    ll a,b;
    cin >> a >> b;
    cout<<myexp(a,b)<<endl;
}
    
int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        test_case();
    }
    
}