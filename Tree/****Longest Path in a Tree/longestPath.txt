#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int> graph[MAX];
vector<bool> visited;
int total(0);

int DFS(int u) {
    int m, m1 = -1, m2 = -1;
    visited[u] = true;

    for(int i : graph[u]) {
        if(!visited[i]) {
            m = DFS(i);
            if(m >= m1) {
                m2 = m1;
                m1 = m;
            } else if(m > m2) {
                m2 = m;
            }
        }
    }

    total = max(total, m1 + m2 + 2);
    return (m1 + 1);
}


int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    

    visited.assign(MAX, false);
    DFS(1);

    cout << total << endl;
}
