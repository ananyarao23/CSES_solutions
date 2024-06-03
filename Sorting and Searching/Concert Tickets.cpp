#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int binSearch(vector<ll> w, ll vac){
    int s = 0,e = w.size()-1;
    while(s <= e){
        int mid = (s+e)/2;
        if(w[mid] <= vac){
            if(mid == w.size()-1) return mid;
            if(w[mid+1] <= vac){
                s = mid+1;
            }
            else return mid;
        }
        else e = mid-1;
    }
    return -1;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> h(n),t(m);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    sort(h.begin(),h.end());
    for (int i = 0; i < m; i++)
    {
        if(t[i] < h[0]){
            cout<<"-1"<<endl;
            continue;
        }
        if(t[i] >= h[h.size()-1]){
            cout<<h[h.size()-1]<<endl;
            h.erase(h.begin()+h.size()-1);
            continue;
        }
        int idx = binSearch(h,t[i]);
        if(idx == -1){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<h[idx]<<endl;
        h.erase(h.begin()+idx);
    }
}