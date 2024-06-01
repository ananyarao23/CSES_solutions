#include <bits/stdc++.h>
using namespace std;

#define ln 1000000007
#define ll long
    
int main(){
    int n; cin >> n;
    char c[n][n];
    ll dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(c[i][j] == '*') dp[i][j] = 0;
            else{
                if(j-1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j-1])%ln;
                if(i-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j])%ln;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}