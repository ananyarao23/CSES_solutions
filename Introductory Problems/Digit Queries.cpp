#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

void solve(ll p){
    ll m = 9;
    ll i=0;
    if(p < 10){
        cout<<p<<endl;
        return;
    }
    do
    {
        i++;
        p = p - m*i;
        m = 10*m;
    } while ((p-(i+1)*m)>0);
    i++;
    ll q = p/i;
    ll r = p%i;
    int s;
    if(r == 0){
        s = int(pow(10,i-1)+q-1)%10;
        cout<<s<<endl;
    }
    else{
        s = (int(pow(10,i-1)+q)/int(pow(10,i-r)))%10;
        cout<<s<<endl;
    }
}
    
int main(){
    int q;
    cin >> q;
    // q = 100;
    while (q--)
    {
        ll p;
        cin >> p;
        // p = 100-q;
        solve(p);
    }
    
}