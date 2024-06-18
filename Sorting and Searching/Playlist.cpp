#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int s = 0, e = 0;
    sort(b.begin(), b.end());
    int uniqueCount = std::unique(b.begin(), b.end()) - b.begin();
    if(uniqueCount == n){
        cout<<n<<endl;
    }
    else{
        unordered_map<ll,int> m;
        int max_len = -1;
        while(s <= e && e < n){
            if(m[a[e]] == 0){
                m[a[e]]++;
                e++;
                continue;
            }
            if(e-s > max_len) max_len = e-s;
            for(;a[s]!=a[e];s++)m[a[s]] = 0;
            s++;e++;
        }
        if(e-s > max_len) max_len = e-s;
        cout<<max_len<<endl;
    }
}