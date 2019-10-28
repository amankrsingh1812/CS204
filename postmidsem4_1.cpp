#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000000];
bool vis[1000000];
int n,m,color[1000000];

bool bipartite(int v)
{
    vis[v]=true;
    bool ans=true;
    for(auto u:adj[v])
    {
        if(vis[u]==false)
        {
            color[u]=1-color[v];
            ans=bipartite(u)&ans;
        }
        else
        {
            if(color[u]==color[v])
                return false;
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool fans=true;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            color[i]=1;
            fans=fans&bipartite(i);
        }
    }
    if(fans)
        cout<<"YES";
    else 
        cout<<"NO";
    return 0;
}
