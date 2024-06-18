#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0,s=0,e=0;
    ll sum = 0;
    while(e < n){
        sum += a[e];
        // cout<<s<<" "<<e<<endl;
        if(sum == x){
            // cout<<s<<" "<<e<<" perfect sum here"<<endl;
            ans++;
            sum -= a[s++];
        }
        else if(sum > x){
            while(sum > x){
                sum -= a[s++];
            }
            if(sum == x){
                // cout<<s<<" "<<e<<" perfect sum here"<<endl;
                ans++;
                sum -= a[s++];
            }
        }
        e++;
    }
    cout<<ans<<endl;
}