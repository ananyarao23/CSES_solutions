#include <bits/stdc++.h>
using namespace std;
    
int main(){
    int num; cin >> num;
    int cnt = 0;
    while(num != 0){
        int i = 0;
        int rem;
        int x;
        do
        {
            i++;
            x = pow(10,i);
            rem = num%x;
        } while (rem == 0);
        rem = (num%x)*10/x;
        num = num - rem;
        cnt++;
    }
    cout<<cnt<<endl;
}