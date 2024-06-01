#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln 1000000007
    
int main(){
    int n; cin >> n;
    int sum = n*(n+1)/2;
    if(sum%2 == 1){
        cout<<"0"<<endl;
        return 0;
    }
    ll cnt[n+1][sum+1];
    memset(cnt,0,sizeof(cnt));
    cnt[1][0] = 0;
    cnt[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        sum = i*(i+1)/2;
        for (int j = 0; j <= sum; j++)
        {
            if(i == j) cnt[i][j] += 2*cnt[i-1][j-i];
            else if(j > i){
                cnt[i][j] += cnt[i-1][j-i];
            }
            else if(j != 0){
                cnt[i][j] += cnt[i-1][i-j];
            }
            cnt[i][j] += cnt[i-1][i+j];
            cnt[i][j] = cnt[i][j]%ln;
        }
    }
    cout<<cnt[n][0]<<endl;
}