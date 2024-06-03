#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

bool comp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}
    
int main(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<pair<ll,int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end(),comp);
    int i = 0,j = n-1;
    while(i<j){
        if (a[i].first+a[j].first == x){
            cout<<a[i].second<<" "<<a[j].second<<endl;
            break;
        }
        if(a[i].first+a[j].first > x){
            j--;
            continue;
        }
        i++;
    }
    if(i == j) cout<<"IMPOSSIBLE"<<endl;
}