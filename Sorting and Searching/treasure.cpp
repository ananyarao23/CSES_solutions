#include <bits/stdc++.h>
using namespace std;
    
#define ll long long

int binSearch(vector<ll> w, ll vac){
    int s = 0,e = w.size()-1;
    while(s <= e){
        // cout<<s<<" "<<e<<endl;
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
    multiset<int,greater<int>> m;
    for (int i = 0; i < 10; i++)
    {
        m.insert(i*i);
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 20; i++)
    {
        cout<<i<<" "<<*(m.lower_bound(i))<<" ";
        cout<<*(m.upper_bound(i))<<endl;
        cout<<endl;
    }
    
}