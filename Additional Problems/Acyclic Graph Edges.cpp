#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        if(a > b) cout<<a<<" "<<b<<endl;
        else cout<<b<<" "<<a<<endl;
    }    
}