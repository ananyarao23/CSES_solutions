#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    int n; cin >> n;
    multiset<ll> m;
    ll x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        auto it = m.upper_bound(x);
        if(it == m.end()){
            m.insert(x);
            continue;
        }
        m.erase(it);
        m.insert(x);
    }
    cout<<m.size()<<endl;
}