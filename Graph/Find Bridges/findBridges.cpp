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
int in[max], low[max];
int timer = 0;

void dfs(int node, int par) {
    visited[node] = true;
    in[node] = low[node] = timer;
    timer++;

    for(int child : graph[node]) {
        if(child == par)
            continue;
        if(visited[child]) {
            /// Edge node-child is a back edge 
            low[node] = min(low[node], in[child]);
        } else {
            /// edge node-child is a forward edge
            dfs(child, node);
            if(low[child] > low[node]) {
                cout << node << " - " << child << " is a bridge" << endl;
            }
            low[node] = min(low[node], low[child]);
        }
    }
}

int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(1, -1);

    return 0;
}
