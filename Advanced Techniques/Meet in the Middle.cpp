#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
ll ans = 0;
 
void solve(int i,int n,ll arr[],ll x,multiset<ll>& v,ll mysum){
    if(i == n){
        v.insert(mysum);
        return;
    }
    if(mysum > x) return;
    solve(i+1,n,arr,x,v,mysum+arr[i]);
    solve(i+1,n,arr,x,v,mysum);
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ll x; cin >> x;
    ll a[n/2],b[n-n/2];
    for (int i = 0; i < n/2; i++) cin >> a[i];
    for (int i = 0; i < n-n/2; i++) cin >> b[i];
    multiset<ll> m1,m2;
    ll sum1 = 0,sum2 = 0;
    solve(0,n/2,a,x,m1,sum1);
    solve(0,n-n/2,b,x,m2,sum2);
    auto it1 = m1.begin();
    for(;it1 != m1.end();it1++){
        auto temp = it1;
        int count = 0;
        while(*temp == *it1){
            temp++;
            count++;
        }
        auto it2 = m2.upper_bound(x-*it1);
        if(it2 == m2.begin()) continue;
        it2--;
        while(*it2 == (x-*it1)){
            ans += count;
            if(it2 == m2.begin()) break;
            it2--;
        }
        it1 = --temp;
    }
    cout<<ans<<endl;
}