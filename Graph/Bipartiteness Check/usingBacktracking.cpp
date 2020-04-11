#include <bits/stdc++.h>
using namespace std;
#define max 100000
vector<int> graph[max];
vector<int> visited;
int color[max];


bool dfs(int v, int c) {
    visited[v] = 1;
    color[v] = c;

    for(int child : graph[v]) {
        if(visited[child] == 0) {
            bool result = dfs(child, c ^ 1);
            if(!result) {
                return false;
            }
        } else if(color[child] == color[v]) {
            return false;
        }
    }
    return true;
}



int main() {
    int t, v, e, count(1);
    int a, b;
    cin >> t;
    while (t--) {
        cin >> v >> e;

        visited.assign(v + 3, 0);
        for(int i = 1; i <= v; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool flag = true;

        for(int i = 1; i <= v; i++) {
            if(visited[i] == 0) {
                bool bicolorable = dfs(i, 0);
                if(!bicolorable) {
                    flag = false;
                    break;
                }
            }
        }

        printf("Is bipartite?\n");
        if(flag)
            printf("Yes\n");
        else
            printf("NO\n");
    }

    return 0;
}