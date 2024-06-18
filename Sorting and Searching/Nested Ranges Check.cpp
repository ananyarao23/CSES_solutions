#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>

bool comp(pair<pl,int> a,pair<pl,int> b){
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}
    
int main(){
    int n; cin >> n;
    vector<pair<pl,int>> ranges(n);
    bool a[n],b[n]; // a --> contains, b --> contained
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].first.first >> ranges[i].first.second;
        ranges[i].second = i;
        a[i] = false;
        b[i] = false;
    }
    sort(ranges.begin(),ranges.end(),comp);
    ll max_y = -1;
    multiset<pi> ends;
    for (int i = 0; i < n; i++)
    {
        if(max_y < ranges[i].first.second){
            max_y = ranges[i].first.second;
            ends.insert({ranges[i].first.second,ranges[i].second});
        }
        else{
            b[ranges[i].second] = true;
            auto it1 = ends.lower_bound({ranges[i].first.second,0});
            for (auto it = it1; it != ends.end(); it++)
            {
                a[it->second] = true;
            }
            ends.erase(it1,ends.end());
            ends.insert({ranges[i].first.second,ranges[i].second});
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout<<((a[i])?1:0)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        std::cout<<((b[i])?1:0)<<" ";
    }
    cout<<endl;
}