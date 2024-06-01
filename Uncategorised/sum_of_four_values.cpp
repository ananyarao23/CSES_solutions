#include <bits/stdc++.h>
using namespace std;



vector<int> check_sum(vector<int> v,int s,unordered_map<int,int> m,unordered_map<int,int> x){
    vector<int> a;
    for (int i = 0; i < v.size(); i++)
    {
        if(m[s-v[i]] == 1 && x[s-v[i]] != i){
            a.push_back(i);
            // cout<<"Pushing "<<i<<" ";
            a.push_back(x[s-v[i]]);
            // cout<<"Pushing "<<x[s-v[i]]<<endl;
            return a;
        }
    }
    return a;
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v1,v2;
    unordered_map<int,int> m1,m2;
    unordered_map<int,int> i1,i2;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if(i < n/2){
            v1.push_back(a);
            m1[a] = 1;
            i1[a] = i;
        }
        else{
            v2.push_back(a);
            m2[a] = 1;
            i2[a] = i-n/2;
        }
    }
    int sz1 = v1.size(), sz2 = v2.size();
    for (int i = 1; i < x; i++)
    {
        vector<int> a1 = check_sum(v1,i,m1,i1);
        vector<int> a2 = check_sum(v2,x-i,m2,i2);
        cout<<a1.size()<<" "<<a2.size()<<endl;
        if(a1.size() == 2 && a2.size() == 2){
            cout<<a1[0]+1<<" "<<a1[1]+1<<" "<<(a2[0]+1+n/2)<<" "<<(a2[1]+1+n/2);
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}