#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    ll n; cin >> n;
    int cnt = 0;
    ll idx = -1;
    for (ll i = 1; cnt <= n*n/2; i++)
    {
        for (ll j = 1; j <= min(n,i) && cnt <= n*n/2; j++)
        {
            if(i%j == 0 && i/j <= n){
                cnt++;
                idx = i;
            }
        }
    }
    cout<<idx<<endl;
}