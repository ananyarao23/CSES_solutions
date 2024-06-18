#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

bool comp(ppi a,ppi b){
    return a.first < b.first;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<ppi> dates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dates[i].first.first >> dates[i].first.second;
        dates[i].second = i;
    }
    sort(dates.begin(),dates.end(),comp);
    vector<int> rooms(n);
    int prev_room = 1;
    multiset<pl> occ_rooms;
    rooms[dates[0].second] = 1;
    occ_rooms.insert({dates[0].first.second,1});
    for (int i = 1; i < n; i++)
    {
        auto it = occ_rooms.begin();
        if(it->first >= dates[i].first.first){
            rooms[dates[i].second] = ++prev_room;
            occ_rooms.insert({dates[i].first.second,prev_room});
            continue;
        }
        int room = it->second;
        occ_rooms.erase(it);
        occ_rooms.insert({dates[i].first.second,room});
        rooms[dates[i].second] = room;
    }
    cout<<prev_room<<endl;
    for(auto c:rooms){
        cout<<c<<" ";
    }
    cout<<endl;
}