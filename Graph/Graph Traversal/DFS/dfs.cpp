/// Time Complexity O(Vertex + edges)

#include <bits/stdc++.h>
using namespace std;
vector<int>gr[1000];
vector<bool> vis;

void dfs(int u)
{
    vis[u] = true;
    cout << u << " ";
    for(int v : gr[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n,m,a,b, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vis.assign(n, false);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(0);
        cout << "\n";
    }
    return 0;
}
