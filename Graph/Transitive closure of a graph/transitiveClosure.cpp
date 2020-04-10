#include <bits/stdc++.h>
using namespace std;
int arr[2000][2000];

vector<int> graph[10000];
vector<int> graphTwo[10000];
bool visited[1000][1000];

void dfs(int parent, int n) {
    visited[parent][n] = true;

    for(int i : graphTwo[n]) {
        if(!visited[parent][i]) {
            dfs(parent, i);
        }
    }
}

void closure(int n) {
    for(int i = 0; i < n; i++) {
        dfs(i, i);
    }

    for(int i = 0; i < n;  i++) {
        for(int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
    }
    cout << "\n";

}


int main() {
    int t, n;


    while(cin >> t) {
        cin >> n;

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                graph[i].push_back(x);
            }
        }


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][i] == 1)
                    graph[i][i] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((graph[i][j] != 0)) {
                    graphTwo[i].push_back(j);
                }
            }
        }

        closure(n);
    }
    return 0;
}
