#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define MAXLEN 1000000
    
int main(){
    int letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }
    string s;
    cin >> s;
    for (int i = 0;i < s.length();i++)
    {
        letters[s[i]-'A']++;
    }
    bool oneOddFound = false;
    int idx = -1;
    int base = int('A');
    bool noSolution = false;
    for (int i = 0; i < 26; i++)
    {
        if(letters[i]%2 != 0){
            if(oneOddFound){
                cout<<"NO SOLUTION"<<endl;
                noSolution = true;
                break;
            }
            oneOddFound = true;
            idx = i;
        }
    }
    if(!noSolution){
        string c = "";
        if(idx != -1){
            c = (char(base+idx));
            letters[idx]--;
        }
        for (int i = 0; i < 26; i++)
        {
            string s(letters[i]/2,char(base+i));
            c = (s+c+s);
        }
        cout<<c<<endl;
    }
}