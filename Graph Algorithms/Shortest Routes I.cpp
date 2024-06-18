#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INTMAX 1000000000
bool spt[100001];

bool comp(pair<int,ll> a,pair<int,ll> b){
        return a.first < b.first;
    }

class myHeap
{
    int num;
    // constructor

public:
    vector<pair<int, ll>> v;
    myHeap(int n)
    {
        num = n;
        for (int i = 1; i < n + 1; i++)
        {
            if(i == 1) v.push_back({i, 0});
            else v.push_back({i, INTMAX});
        }
        
    }

    void decrease_priority(int idx, ll val)
    {
        for (int i = 0; i < num; i++)
        {
            if (v[i].first == idx)
            {
                if(v[i].second <= val) break;
                v[i].second = val;
                build_heap(i);
                return;
            }
        }
    }

    pair<int,ll> get_minimum()
    {
        auto temp = v[num - 1];
        v[num - 1] = v[0];
        v[0] = temp;
        int ans1 = v[num - 1].first,ans2 = v[num-1].second;
        num--;
        heapify(0);
        return {ans1,ans2};
    }

    void print_distances(int n){
        sort(v.begin(),v.end(),comp);
        for (int i = 0; i < n; i++)
        {
            cout<<v[i].second<<" ";
        }
        cout<<endl;
    }

private:
    void heapify(int i)
    {
        ll min_item;
        if(2*i+1 >= num) return;
        min_item = min(v[i].second, v[2 * i + 1].second);
        if(2*i+2 < num) min_item = min(min_item, v[2 * i + 2].second);
        if (min_item == v[i].second)
            return;
        if (min_item == v[2 * i + 1].second)
        {
            auto temp = v[i];
            v[i] = v[2 * i + 1];
            v[2 * i + 1] = temp;;
            heapify(2 * i + 1);
        }
        else
        {
            auto temp = v[i];
            v[i] = v[2 * i + 2];
            v[2 * i + 2] = temp;
            heapify(2 * i + 2);
        }
        return;
    }
    void build_heap(int idx)
    {
        if(idx == 0) return;
        if (v[idx].second < v[(idx - 1) / 2].second)
        {
            auto temp = v[(idx - 1) / 2];
            v[(idx - 1) / 2] = v[idx];
            v[idx] = temp;
            build_heap((idx - 1) / 2);
        }
    }
};


void dijsktra(int i, ll **g, int n)
{
    myHeap heap(n);
    int cnt = 0;
    while (cnt < n)
    {
        auto ans = heap.get_minimum();
        int idx = ans.first;
        ll val = ans.second;
        cnt++;
        for (int i = 1; i < n + 1; i++)
        {
            if (g[idx][i])
            {
                heap.decrease_priority(i,val+g[idx][i]);
            }
        }
    }
    heap.print_distances(n);
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    ll **g = new ll *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        g[i] = new ll[n + 1];
        memset(g[i], 0, (n + 1) * sizeof(ll));
        spt[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (g[a][b])
            g[a][b] = min(g[a][b], c);
        else
            g[a][b] = c;
    }
    dijsktra(1, g, n);
}