#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pi pair<int,int>
#define pip pair<int,pair<int,int>>

    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    ll a[n];
    ll sum = 0;
    ll p[n];
    cin >> a[0];
    p[0] = a[0];
    for (int i = 1; i < n; i++){
        cin >> a[i];
        p[i] = a[i] + p[i-1];
    }
    for (int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        ll ans = p[b-1];
        if(a > 1){
            ans = ans - p[a-2];
        }
        cout<<ans<<endl;
    }
}