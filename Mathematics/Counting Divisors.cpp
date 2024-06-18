#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ll num[n];
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    vector<ll> d(10000001);
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            d[j]++;
        }
    }
    for(auto c:num){
        cout<<d[c]<<endl;
    }
}