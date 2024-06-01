#include <bits/stdc++.h>
using namespace std;

int oui(int a,int b,int m,set<int>& s){
    if(a == 0){
        for (int i = 1; i <=m ; i++) s.insert(i);
        return m;
    }
    if(b == 0 || a == b){
        s.insert(a-1);
        s.insert(a);
        s.insert(a+1);
        return 3;
    }
    if(abs(a-b) > 2) return 0;
    if(abs(a-b) == 1){
        s.insert(a);
        s.insert(b);
        return 2;
    }
    s.insert((a+b)/2);
    return 1;
}
    
int main(){
    int n,m; cin >> n >> m;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 1;
    vector<set<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0){
            dp[i].insert(arr[i]);
            continue;
        }
        if(i-1 >= 0 && i+1 <= n-1){
            
        }
    }
    
}