/// Time Complexity O(vertex + edges)

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<bool> visited;
vector<int> graph[MAX];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int f = q.front();
        q.pop();
        cout << f << " ";
        for(auto i : graph[f]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    visited.assign(n, false);
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);

    return 0;
}