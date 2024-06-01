#include <bits/stdc++.h>
using namespace std;

#define INTMAX 10000000

int main(){
    int n,s; cin >> n >> s;
    vector<int> coins(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(s+1,INTMAX);
    for(auto c:coins){
        if(c <= s) dp[c] = 1;
    }
    for (int i = 1; i < s+1; i++)
    {
        for(auto c:coins){
            if(c <= i){
                dp[i] = min(dp[i],1 + dp[i-c]);
            }
        }
    }
    if(dp[s] == INTMAX) cout<<-1<<endl;
    else cout<<dp[s]<<endl;
}