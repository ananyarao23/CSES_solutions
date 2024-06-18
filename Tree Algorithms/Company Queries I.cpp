#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
const int nmax = 2e+5 + 1;
const int LOG = log2(nmax)+1;

void solve(int node,int k,int **dp){
    for (int i = 0; i <= LOG; i++)
    {
        if((k >> i) & 1) node = dp[i][node];
    }
    if(node == 0) cout<<"-1"<<endl;
    else cout<<node<<endl;
}

    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    // cout<<"yha"<<endl;
    cin >> n >> q;
    // cout<<"idhar"<<endl;
    int** dp = new int*[LOG+1];
    for (int i = 0; i <= LOG; i++)
    {
        dp[i] = new int[n+1];
    }
    // cout<<"kuch bhi"<<endl;
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> dp[0][i];
    }
    // cout<<"ehfbeh"<<endl;
    for (int i = 1; i <= LOG; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // cout<<"i,j: "<<i<<","<<j<<endl;
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    // cout<<"here"<<endl;
    for (int i = 0; i < q; i++)
    {
        int node,k;
        cin >> node >> k;
        solve(node,k,dp);
    }
    
    
}