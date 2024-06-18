#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

bool comp(pl a,pl b){
    return a.first < b.first;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<pl> sched(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sched[i].first >> sched[i].second;
    }
    sort(sched.begin(),sched.end(),comp);
    ll time_spent = 0;
    ll reward = 0;
    for (int i = 0; i < n; i++)
    {
        time_spent += sched[i].first;
        reward += (sched[i].second - time_spent);
    }
    cout<<reward<<endl;
}