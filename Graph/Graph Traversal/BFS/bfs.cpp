/// Time Complexity O(vertex + edges)

#include <bits/stdc++.h>
#define max 10000000 + 5
#define mod 10000000 + 5
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define lli long long int
#define endl '\n'
using namespace std;

vi graph[max];
bool visited[max];
int dis[max];
queue<int> que;

void bfs(int node) {
    visited[node] = true;
    dis[node] = 0;
    que.push(node);

    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        // cout << cur << " ";
        for (int child : graph[cur]) {
            if(!visited[child]) {
                que.push(child);
                dis[child] = dis[cur] + 1;
                visited[child] = true;
            }
        }
    }
}

int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int v, e, a, b;

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bfs(1);
    cout << endl;

    for (int i = 1; i <= v; i++)
        cout << dis[i] << endl;

    return 0;
}
