#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

bool comp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int,int>> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(),t.end(),comp);
    int ans = 1;
    multiset<int> m;
    m.insert(t[0].second);
    for (int i = 1; i < n; i++)
    {
        auto it = m.upper_bound(t[i].first);
        if(it == m.begin()){
            m.insert(t[i].second);
            if(m.size() > ans) ans = m.size();
            continue;
        }
        m.erase(m.begin(),it);
        m.insert(t[i].second);
        if(m.size() > ans) ans = m.size();
    }
    cout<<ans<<endl;
}