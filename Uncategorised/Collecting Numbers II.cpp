#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

void myswap(pair<int,int>& a,pair<int,int>& b){
    int temp = a.second;
    a.second = b.second;
    b.second = temp;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> arr(n);
    vector<pair<int,int>> s(m);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    for (int i = 0; i < m; i++){
        cin >> s[i].first >> s[i].second;
    }
    sort(arr.begin(),arr.end(),comp);
    vector<int> count(m,0);
    for (int i = 0; i < m; i++)
    {
        myswap(arr[s[i].first-1],arr[s[i].second-1]);
        
    }
    
}