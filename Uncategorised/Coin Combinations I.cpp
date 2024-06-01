#include <bits/stdc++.h>
using namespace std;

#define ln 1000000007
#define ll long
int main(){
    int n,s; cin >> n >> s;
    vector<ll> coins(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<ll> dp(s+1,0);
    dp[0] = 1;
    for (int i = 1; i < s+1; i++)
    {
        for(auto c:coins){
            if(c <= i){
                dp[i] += dp[i-c];
            }
        }
        dp[i] = dp[i]%ln;
    }
    cout<<dp[s]<<endl;
}