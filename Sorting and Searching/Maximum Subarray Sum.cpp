#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int n; cin >> n;
    ll a[n];
    ll sl[n],sr[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sr[0] += a[i];
    }
    sl[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        sl[i] = sl[i-1]+a[i];
        sr[i] = sr[i-1]-a[i-1];
    }
    ll mx = 1000000000,my = -1;
    int s = 0,e = n-1;
    
}