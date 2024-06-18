#include <bits/stdc++.h>
using namespace std;

#define ll long long

int findWinningPlayer(vector<int> &skills, int k)
{
    int wins = 0;
    queue<pair<int, int>> q;
    stack<int> s;
    s.push(skills[0]);
    int idx = 0, max = -1;
    if (k >= skills.size())
    {
        for (int i = 0; i < skills.size(); i++)
        {
            if (skills[i] > max)
            {
                max = skills[i];
                idx = i;
            }
        }
        return idx;
    }
    for (int i = 1; i < skills.size(); i++)
    {
        if (s.top() > skills[i])
        {
            wins++;
            skills.push_back(skills[i]);
        }
        else
        {
            skills.push_back(s.top());
            s.pop();
            s.push(skills[i]);
            wins = 1;
            idx = i;
        }
        if (wins == k)
            return idx;
    }
    return 0;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> skills(n);
    for (int i = 0; i < n; i++) cin >> skills[i];
    cout<<findWinningPlayer(skills,k);
}