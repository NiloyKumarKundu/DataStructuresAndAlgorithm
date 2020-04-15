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

bool dfs(int node, int parent) {
    visited[node] = true;
    for(int child : graph[node]) {
        if(!visited[child]) {
            if(dfs(child, node)) {
                return true;
            }
        } else if(child != parent) {
            return true;
        }
    }
    return false;
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

        bool result = dfs(1, 1);
        if(result) {
            cout << "Cycle Found!" << endl;
        } else {
            cout << "No Cycle Found!" << endl;
        }

        return 0;
}
