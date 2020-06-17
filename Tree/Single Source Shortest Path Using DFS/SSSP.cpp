#include <bits/stdc++.h>
using namespace std;
vector<int> gr[1000];
bool vis[1000];
int dis[1000];

void dfs(int u, int d) {
    vis[u] = true;
	dis[u] = d;
	for (int v : gr[u]) {
		if (!vis[v]) {
            dfs(v, d + 1);
        }
	}
}

int main() {
    int n, m, a, b, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(2, 0);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if(max < dis[i]) {
			max = dis[i];
		}
	}
	cout << max << endl;
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	cout << "\n";
	return 0;
}
