#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define NO "NO"
#define YES "YES"

void print_answer(char c[],int n){
    cout<<YES<<endl;
    vector<int> v1,v2;
    for (int i = 0; i < n; i++)
    {
        if(c[i] == '0') v1.push_back(i+1);
        else v2.push_back(i+1);
    }
    cout<<v1.size()<<endl;
    for(auto c:v1) cout<<c<<" ";
    cout<<endl<<v2.size()<<endl;
    for(auto c:v2) cout<<c<<" ";
}

bool solve(int n,int s,char c[],int sum,int N){
    cout<<"here"<<endl;
    if(s == sum/2 ){
        //
        print_answer(c,N);
        return true;
    }
    // include n
    if(solve(n-1,s,c,sum,N)) return true;
    c[n-1] = '1';
    if(solve(n-1,s+n,c,sum,N)) return true;
    return false;
}

    
int main(){
    int n; cin >> n;
    int sum = n*(n+1)/2;
    if(sum%2 != 0){
        cout<<NO<<endl;
        // return 1;
    }
    else{
        int s1 = 0;
        char c[n];
        for(int i=0;i<n;i++)c[i] = '0';
        solve(n,s1,c,sum,n);
    }
}