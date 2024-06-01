#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
ll min_diff = 1000000000;

void rec(ll v[],ll s1,ll s2,int n){
    if(n == 0){
        if(abs(s1-s2) < min_diff) min_diff = abs(s1-s2);
        return;
    }
    // nth element included in s1
    rec(v,s1+v[n-1],s2,n-1);
    // nth element included in s2
    rec(v,s1,s2+v[n-1],n-1);
}

int main(){
    int n; cin >> n;
    ll v[n];
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll s1 = 0,s2 = 0;
    rec(v,s1,s2,n);
    cout<<min_diff<<endl;
}