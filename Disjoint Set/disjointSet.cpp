#include <bits/stdc++.h>
#define endl '\n'
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
 
int parent[MAX];
 
int find(int a) {
    if(parent[a] < 0) {
        return a;
    } else {
        return parent[a] =  find(parent[a]);
    }
}
 
void Union(int a, int b) {
    parent[a] += parent[b];
    parent[b] = a;
}
 
int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, u, v, a, b;
    cin >> n >> m;
 
    for(int i = 0; i <= n; i++) {
        parent[i] = -1;
    }
 
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a != b) {
            Union(a, b);
        }
    }
 
 
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << " ";
    }

   cout << endl;
 
    return 0;
}