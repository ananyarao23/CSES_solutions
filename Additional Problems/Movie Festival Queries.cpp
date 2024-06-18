#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pi pair<int,int>

int prev(multiset<pi> m,multiset<pi>::iterator it_begin,multiset<pi>::iterator it){
    int j = 0;
    auto iter = it;
    while(it_begin != iter){
        j++;
        iter--;
        if(iter->second <= it->first) return j;
    }
    return -1;
}

int main(){
    int n,k;
    cin >> n >> k;
    multiset<pi> m;
    pi q[k];
    for (int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        m.insert({a,b});
    }
    for (int i = 0; i < k; i++) cin >> q[i].first >> q[i].second;
    for(auto c:q){
        int x = c.first,y = c.second;
        auto it = m.lower_bound(c);
        auto iter = it;
        int dp[n+1];
        dp[0] = 0;
        int j = 1;
        while(iter->second <= y && iter != m.end()){
            cout<<"here"<<endl;
            int i = prev(m,it,iter);
            if(i == -1) dp[j] = 1;
            dp[j] = max(dp[j-1],dp[j-i]+1);
            iter++;
            j++;
        }
        cout<<dp[j-1]<<endl;
    }
}