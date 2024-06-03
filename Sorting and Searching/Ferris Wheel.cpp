#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int n; cin >> n;
    ll x, w[n];
    cin >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w,w+n);
    int ans = 0;
    int s=0,e=n-1;
    while(s < e){
        if(w[s]+w[e] <= x){
            ans++;
            s++;
            e--;
        }
        else{
            ans++;
            e--;
        }
    }
    if(s == e) ans++;
    cout<<ans<<endl;
}