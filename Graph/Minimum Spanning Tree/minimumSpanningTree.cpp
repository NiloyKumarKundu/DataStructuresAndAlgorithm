#include<bits/stdc++.h>
using namespace std;

int main () {
    int V, E;
    cin >> V >> E;
    vector<int> G[V];
    
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < E; j++) {
            G[i].push_back(0);
        }
    }

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c;
        G[b][a] = c;
    }

    int edge;

    int visit[V];

    for(int i=0;i<V;i++){
        visit[i]=false;
    }
    edge = 0;
    visit[0] = true;

    int x;
    int y;

    cout << "For minimum spanning tree, accepted weights are: ";
    while (edge < V - 1) {
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (visit[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visit[j] && G[i][j]) { // not in selected and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << G[x][y] << " ";
        visit[y] = true;
        edge++;
    }


    return 0;
}
