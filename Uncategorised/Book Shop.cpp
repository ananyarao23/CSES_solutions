#include <bits/stdc++.h>
using namespace std;

#define INTMIN -1000000000
    
int main(){
    int n,mp; cin >> n >> mp;
    vector<int> pr(n,0);
    vector<int> pg(n,0);
    for (int i = 0; i < n; i++) cin >> pr[i];
    for (int i = 0; i < n; i++) cin >> pg[i];
    vector<set<int>> dp_set(mp+1);
    vector<int> dp(mp+1);
    for (int i = 1; i < mp+1; i++)
    {
        for(int j=0;j<n;j++){
            if(pr[j] <= i && (dp_set[i-pr[j]].find(j) == dp_set[i-pr[j]].end())){
                if(dp[i] < (pg[j]+dp[i-pr[j]])){
                    dp[i] = (pg[j]+dp[i-pr[j]]);
                    dp_set[i] = dp_set[i-pr[j]];
                    dp_set[i].insert(j);
                }
            }
        }
    }
    cout<<dp[mp]<<endl;
}