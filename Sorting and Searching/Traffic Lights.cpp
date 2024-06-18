#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pi pair<int,int>

int main(){
    set<pi> ranges;
    multiset<int> lengths;
    int x,n;
    cin >> x >> n;
    ranges.insert({0,x});
    lengths.insert(x);
    for (int i = 0; i < n; i++)
    {
        int p; cin >> p;
        auto it = ranges.upper_bound({p,0});
        it--;
        int l = it->first,r = it->second;
        lengths.erase(lengths.find(r-l));
        lengths.insert(r-p);
        lengths.insert(p-l);
        ranges.erase(it);
        ranges.insert({l,p});
        ranges.insert({p,r});
        auto iter = lengths.end();
        cout<<*(--iter)<<" ";
    }
    
}