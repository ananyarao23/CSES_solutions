#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

void solve(int n,ll c[]){
    ll mysum = 0;
    for(int i=0;i<n;i++){
        if(c[i] > mysum+1){
            cout<<mysum+1<<endl;
            return;
        }
        mysum += c[i];
    }
    cout<<mysum+1<<endl;
    return;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ll c[n];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c,c+n);
    solve(n,c);
}