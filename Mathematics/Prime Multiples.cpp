#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;
    
#define ll long long
#define pl pair<ll,ll>
#define ppi pair<pl,int>
#pragma GCC optimize("O3")

string generate_bit_string(ll n,int k){
    string bit_mask = "";
    while(n > 0){
        int rem = n%2;
        bit_mask = to_string(rem) + bit_mask;
        n = n/2;
    }
    while(bit_mask.length() < k) bit_mask = "0" + bit_mask;
    return bit_mask;
}

ll power(ll a,ll b){
    if(a == 1) return 1;
    if(a == -1){
        if(b%2 == 0) return 1;
        return -1;
    }
    if(b == 1) return a;
    ll ans = power(a,b/2);
    if(b%2 == 0) return ans*ans;
    return a*ans*ans;
}

ll set_val(ll n,ll primes[],ll num,int k){
    string bit_mask = generate_bit_string(n,k);
    ll prod = 1;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if(bit_mask[i] == '1'){
            prod = prod*primes[i];
            if(prod > num) return 0;
            cnt++;
        }
    }
    return power(-1,cnt+1)*(ll)(num/prod);
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin >> n >> k;
    ll dec_k = 1 << k;
    ll ans = 0;
    ll primes[k];
    for (int i = 0; i < k; i++) cin >> primes[i];
    for (int i = 1; i < dec_k; i++)
    {
        ans += set_val(i,primes,n,k);
    }
    cout<<ans<<endl;
}