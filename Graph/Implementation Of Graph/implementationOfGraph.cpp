#include <bits/stdc++.h>

using namespace std;

int main() {
    int vertex, edges, x, y;
    cin >> vertex >> edges;
    vector<int> vc[vertex];
    for (int i = 0; i < edges; i++) {
        cin >> x >> y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }

    for (int i = 0; i < vertex; i++) {
        cout << i;
        for (auto n : vc[i]) {
            cout << "-> " << n;
        }
        cout << "\n";
    }
    return 0;
}


