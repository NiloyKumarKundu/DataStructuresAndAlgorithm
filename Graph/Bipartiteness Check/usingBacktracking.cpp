#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
vector<int> graph[MAX];
vector<bool> visited;
int color[MAX];

void DFS(int n) {
    visited[n] = true;

    for(auto i : graph[n]) {
        if(color[n] == 0)
            color[i] = 1;
        else if(color[n] == 1)
            color[i] = 0;
        if(!visited[i]) {
            DFS(i);
        }
    }
}


int main() {
    int v, e, a, b;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited.assign(v, false);

    DFS(a);
    int c;
    bool bicolorable = true;
    for(int i = 0; i < v; i++) {
        if(graph[i].size() > 0) {
            c = color[i];

            for(int j = 0; j < graph[i].size(); j++) {
                if(c == color[graph[i][j]]) {
                    bicolorable = false;
                    break;
                }
            }
        }

        if(!bicolorable)
            break;

    }

    if(bicolorable)
        cout << "YES\n";
    else
        cout << "NO\n";
}

