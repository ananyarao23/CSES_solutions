#include <bits/stdc++.h>
using namespace std;

#define ll long long
    
int main(){
    ll n; cin >> n;
    ll a[n-1];
    ll sum = 0;
    for (int i = 0; i < n-1; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll complete_sum = n*(n+1)/2;
    // cout<<complete_sum<<" "<<sum<<endl;
    cout<<complete_sum-sum<<endl;
}