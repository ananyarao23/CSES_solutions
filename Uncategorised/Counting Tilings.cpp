#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    int ans = 1;
    do
    {
        ans = ans*n;
    } while (--n);
    return ans;
}

int nCr(int n,int r){
    int ans = fact(n)/(fact(n-r)*fact(r));
    return ans;
}

int value(int n){
    int half = n/2;
    int ans = 1;
    for (int i = 1; i <= half; i++)
    {
        ans += nCr(n-1,i);
    }
    return ans;
}

    
int main(){
    int n,m; cin >> n >> m;
    int dp[m+1];
    dp[0] = 1;
    int val = value(n);
    
}