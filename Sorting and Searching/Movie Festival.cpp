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
#define ff first
#define ss second

bool comp(pl a,pl b){
    return a.ss < b.ss;
}

int prev_movie(vector<pl> movies,int k){
    int s=0,e=k-1,mid;
    while(s <= e){
        mid = (s+e)/2;
        if(movies[mid].ss <= movies[k].ff){
            if(mid == e || movies[mid+1].ss > movies[k].ff){
                return mid;
            }
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<pl> movies;
    for (int i = 0; i < n; i++)
    {
        ll a,b; cin >> a >> b;
        movies.push_back({a,b});
    }
    sort(movies.begin(),movies.end(),comp);
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int prev = prev_movie(movies,i);
        if(prev == -1) dp[i] = max(dp[i-1],1);
        else dp[i] = max(dp[i-1],1+dp[prev]);
    }
    cout<<dp[n-1]<<endl;
}