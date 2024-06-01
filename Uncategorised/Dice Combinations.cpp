#include <bits/stdc++.h>
using namespace std;

#define ll long 
#define ln 1000000007
    
int main(){
    int n; cin >> n;
    vector<ll> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n+1; i++)
    {
        for (int j = i-1; j >= max(i-6,0); j--)
        {
            dp[i] = (dp[i] + dp[j])%ln;
        }
    }
    cout<<dp[n]<<endl;
}