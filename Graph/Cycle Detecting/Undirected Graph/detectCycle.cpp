#include<bits/stdc++.h>
using namespace std;
vector<int> vc[10000];
vector<bool> visited;
bool result = false;


bool dfs(int v, int parent) {
    visited[v] = true;

    for(int i : vc[v]) {
        if(!visited[i]) {
            dfs(i, v);
        } else if(visited[i] && i != parent) {
            return result = true;
        }
    }
    return result;
}

int main () {
    int V, E;
    cin >> V >> E;
    visited.assign(V, false);
    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }

    bool ans = dfs(0, -1);
    if(ans) {
        cout << "Cycle Found!" << endl;
    } else {
        cout << "Cycle Not Found" << endl;
    }
    
    return 0;
}
