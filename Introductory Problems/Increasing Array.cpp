#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if(a[i] < a[i-1]){
            ans +=(a[i-1]-a[i]);
            a[i] = a[i-1];
        }
    }
    cout<<ans<<endl;
}