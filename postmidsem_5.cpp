#include <bits/stdc++.h>
using namespace std;
const int N = 300000,M=1e+9 +7;

int parent[N], rank1[N], n;

void make_set(int x)
{
    parent[x] = x;
    rank1[x] = 1;
    return;
}

int find_set(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find_set(parent[x]);
}

void munion(int x, int y)
{
    int a = find_set(x), b = find_set(y);
    if (a != b)
    {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        if (rank1[a] == rank1[b])
            rank1[a]++;
    }
    return;
}

struct Edge
{
    int u, v;
    long long int w;
};

bool comp(Edge e1, Edge e2)
{
    return e1.w > e2.w;
}
int main()
{
    int n,m;
    long long int cost=1;
    cin >> n>>m;
    vector<Edge> edge,ans;
    for (int i = 0; i < m; i++)
    {
        // make_set(i);
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edge.push_back(e);
    }
    for(int i=1;i<=n;i++)
        make_set(i);
    sort(edge.begin(), edge.end(), comp);
    for(Edge e:edge)
    {
        int a=find_set(e.u),b=find_set(e.v);
        if(a!=b)
        {
            cost=((cost*e.w)%M+M)%M;
            ans.push_back(e);
            munion(a,b);
        }
    }
    cout<<cost;
    return 0;
}
