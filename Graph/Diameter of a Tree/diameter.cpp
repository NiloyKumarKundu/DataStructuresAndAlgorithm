// Time complexity O(N)


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
int maxD, maxNode;

void dfs(int node, int dis) {
    visited[node] = true;
    if(dis > maxD) {
        maxD = dis;
        maxNode = node;
    }

    for(int child : graph[node]) {
        if(!visited[child]) {
            dfs(child, dis+ 1);
        }
    }
}

int main()
{
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    maxD = -1;
    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    maxD = -1;
    dfs(maxNode, 0);

    cout << maxD << endl;

    return 0;
}
