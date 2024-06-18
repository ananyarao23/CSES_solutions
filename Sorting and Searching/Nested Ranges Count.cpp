#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>

bool comp(pair<pl,int> a,pair<pl,int> b){
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}

// struct compare {
//     bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
//         return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
//     }
// };
    
int main(){
    int n; cin >> n;
    vector<pair<pl,int>> ranges(n);
    int a[n],b[n]; // a --> contains, b --> contained
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].first.first >> ranges[i].first.second;
        ranges[i].second = i;
        a[i] = 0;
        b[i] = 0;
    }
    sort(ranges.begin(),ranges.end(),comp);
    ll max_y = -1;
    multiset<pi> ends;
    for (int i = 0; i < n; i++)
    {
        if(max_y < ranges[i].first.second){
            max_y = ranges[i].first.second;
        }
        else{
            auto it = ends.lower_bound({ranges[i].first.second,0});
            b[ranges[i].second] = distance(ends.end(),it);
        }
        ends.insert({ranges[i].first.second,ranges[i].second});
    }
    ends.clear();
    multiset<pi> endr;
    ll min_y = 1000000000;
    for (int i = n-1; i >= 0; --i)
    {
        if(ranges[i].first.second < min_y){
            min_y = ranges[i].first.second;
        }
        else{
            for (auto i = endr.begin(); i != endr.end(); i++)
            {
                cout<<i->first<<"_"<<i->second;
            }
            cout<<endl;
            auto it = endr.upper_bound({ranges[i].first.second,0});
            cout<<it->first<<" "<<it->second<<endl;
            it--;
            a[ranges[i].second] = distance(it,endr.begin())+1;
            cout<<"total numbers: "<<a[ranges[i].second]<<endl;
        }
        endr.insert({ranges[i].first.second,ranges[i].second});
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        std::cout<<b[i]<<" ";
    }
    cout<<endl;
}