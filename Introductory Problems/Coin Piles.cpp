#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

void test_case(){
    ll a,b; cin >> a >> b;
    ll x = 2*a-b;
    ll y = 2*b-a;
    if(x%3 == 0 && x >= 0 && y%3 == 0 && y >= 0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
    
int main(){
    int t; cin >> t;
    while(t--) test_case();
}