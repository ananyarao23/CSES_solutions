#include <bits/stdc++.h>
using namespace std;
    
int main(){
    std::ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<int>> dp(n+1);
    int max_len=0;
    for (int i = 0; i < n; i++)
    {
        if(max_len == 0){
            max_len++;
            dp[1].push_back(a[i]);
            continue;
        }
        bool found = false;
        for (int j = max_len; j >= 1; j--)
        {
            for (int k = 0; k < dp[j].size(); k++)
            {
                if(dp[j][k] < a[i]){
                    dp[j+1].push_back(a[i]);
                    dp[j].erase(dp[j].begin()+k);
                    if(j > 2) dp[j-1].clear();
                    if(j+1 > max_len) max_len = j+1;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) dp[1].push_back(a[i]);
    }
    cout<<max_len<<endl;
}