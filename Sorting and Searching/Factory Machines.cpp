#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppl pair<pl,ll>
#pragma GCC optimize("O3")
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,t;
    cin >> n >> t;
    int build_time[n],rt[n];
    for (int i = 0; i < n; i++){
        cin >> build_time[i];
        rt[i] = 0;
    }
    
}