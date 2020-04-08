#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
vector<int> g[MAX];
vector<bool> visited;
vector<int> component;
int n;

void dfs(int v) {
    visited[v] = true;
    component.push_back(v);
    for (auto i : g[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int find_comps() {
    int connected(0);
    for (int i = 0; i < n ; i++) {
        if (!visited[i]) {
            component.clear();
            dfs(i);
            connected++;
            cout << "Component: ";
            for (int j = 0; j < component.size(); j++) {
                cout << component[j] << " ";
            }
            cout << endl;
        }
    }
    return connected;
}


int main() {
    int x;
    cin >> n >> x;

    visited.assign(n, false);

    for(int i = 0; i < x; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int count = find_comps();
    cout << count << endl;
}
