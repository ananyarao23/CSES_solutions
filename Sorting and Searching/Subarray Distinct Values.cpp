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
    std::cout.tie(NULL);
    int n,k; cin >> n >> k;
    ll a[n];
    ll max_num = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max_num) max_num = a[i];
    }
    int s=0,e=0,num_dist = 0,num_count[max_num+1];
    for (int i = 0; i < max_num+1; i++)
    {
        num_count[i] = 0;
    }
    ll ans = 0;
    while(e < n){
        if(num_count[a[e]] == 0){
            num_dist++;
            num_count[a[e]] = 1;
            while(num_dist > k){
                num_count[a[s]]--;
                if(num_count[a[s]] == 0){
                    s++;
                    num_dist--;
                    continue;
                }
                ans += (n-e);
                s++;
            }
        }
        else{
            num_count[a[e]]++;
        }
        e++;
    }
    ans = n*(n-1)/2-ans;
    std::cout<<ans<<endl;
}