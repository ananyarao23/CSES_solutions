#include <bits/stdc++.h>
using namespace std;

#define ll long long
    
int main(){
    ll n; cin >> n;
    cout<<n<<" ";
    while(n != 1){
        if(n%2 == 0) n = n >> 1;
        else{
            n = (n << 1) + n + 1;
        }
        cout<<n<<" ";
    }
}