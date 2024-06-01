#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct project{
    ll start,finish,reward;
};

bool comp(project p1, project p2){
    return p1.finish < p2.finish;
}

int get_prev(project p[],int i){
    int low = 0, high = i - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (p[mid].finish < p[i].start) {
            if (p[mid + 1].finish < p[i].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    project p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].start >> p[i].finish >> p[i].reward;
    sort(p,p+n,comp);
    ll* dp = new ll[n];
    dp[0] = p[0].reward;
    int j;
    ll moni;
    for (int i = 1; i < n; i++)
    {
        moni = p[i].reward;
        j = get_prev(p,i);
        if(j != -1) moni += dp[j];
        dp[i] = max(dp[i-1],moni);
    }
    cout<<dp[n-1]<<endl;
    delete[] dp;
}