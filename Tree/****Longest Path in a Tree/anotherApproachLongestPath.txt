// Eta Bojha easy!

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int> graph[MAX];
vector<bool> visited;
int maxD, maxNode;

void DFS(int Node, int distance) {
    visited[Node] = true;
    if(distance > maxD) {
        maxD = distance;
        maxNode = Node;
    }

    for(int child : graph[Node]) {
        if(!visited[child]) {
            DFS(child, distance + 1);
        }
    }
}


int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited.assign(n, false);
    maxD = -1;
    DFS(1, 0);

    visited.assign(n, false);
    maxD = -1;
    DFS(maxNode, 0);
    cout << maxD << "\n";
}