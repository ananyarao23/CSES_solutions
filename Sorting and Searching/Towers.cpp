#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

bool comp(pair<ll,int> a,pair<ll,int> b){
    if(a.first == b.first){
        return b.second < a.second;
    }
    return b.first < a.first;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<pair<ll,int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end(),comp);
    int ans = 0;
    while (v.size() != 0){
        ll idx = v[0].second;
        v.erase(v.begin());
        for (int i = 0; i < v.size(); i++)
        {
            if(v[i].second > idx){
                idx = v[i].second;
                v.erase(v.begin()+i);
                i--;
            }
        }
        ans++;
    }
    cout<<ans<<endl;
}