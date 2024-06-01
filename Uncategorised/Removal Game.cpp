#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXSIZE 5000
ll a[MAXSIZE];
ll dp[MAXSIZE][MAXSIZE];

ll solve(int i,int j){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll v1 = a[i] + min(solve(i+1,j-1),solve(i+2,j));
    ll v2 = a[j] + min(solve(i+1,j-1),solve(i,j-2));
    dp[i][j] = max(v1,v2);
    return dp[i][j];
}
    
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n-1);
}