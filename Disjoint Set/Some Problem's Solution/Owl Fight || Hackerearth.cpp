#include <bits/stdc++.h>
#define endl '\n'
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
 
int parent[MAX];
 
int findRecursive(int a) {
    if(parent[a] < 0) {
        return a;
    } else {
        return parent[a] = findRecursive(parent[a]);
    }
}


void Union(int a, int b) {
    parent[a] = min(parent[a], parent[b]);
    parent[b] = a;
}
 
int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, u, v, a, b, q;
    cin >> n >> m;
 
    for(int i = 1; i <= n; i++) {
        parent[i] = -i;
    }
 
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a = findRecursive(a);
        b = findRecursive(b);
        if(a != b) {
            Union(a, b);
        }
    }
    cin >> q;
    while(q--) {
        cin >> a >> b;
        int parA = findRecursive(a);
        int parB = findRecursive(b);

        if(parA == parB) {
            cout << "TIE" << endl;
        } else  {
            if(parent[parA] < parent[parB]) {
                cout << a << endl;
            } else {
                cout << b << endl;
            }
        }
    }
    return 0;
}