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
int subSize[max];

int dfs(int node) {
    visited[node] = true;
    int cur_size = 1;

    for(int child : graph[node]) {
        if(!visited[child]) {
            cur_size += dfs(child);
        }
    }

    subSize[node] = cur_size;
    return cur_size;
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

    dfs(1);
    cin >> a;

    cout << subSize[a] << endl;
    for (int i = 1; i <= v; i++) {
        cout << subSize[i] << endl;
    }


    return 0;
}
