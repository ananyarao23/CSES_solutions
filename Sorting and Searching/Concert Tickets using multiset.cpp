#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    multiset<int> h;
    ll x;
    for (int i = 0; i < n; i++){
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        auto it = h.lower_bound(x);
        if(*it == x){
            cout<<x<<endl;
        }
        else if(it == h.begin()){
            cout<<"-1"<<endl;
            continue;
        }
        else{
            it--;
            cout<<*it<<endl;
        }
        h.erase(it);
    }
}