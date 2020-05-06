#include <bits/stdc++.h>
#define max 1000000 + 5
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
vi primes;
bool visited[max];
int dis[max];

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true; 
}

bool isValid(int a, int b) {
    int count = 0;
    while(a > 0) {
        if((a % 10) != (b % 10)) {
            count++;
        }
        a /= 10; 
        b /= 10;
    }
    if(count == 1) {
        return true;
    } else {
        return false;
    }
}

void buildGraph() {
    for(int i = 1000; i <= 9999; i++) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }

    for(int i = 0; i < primes.size(); i++) {
        for(int j = i + 1; j < primes.size(); j++) {
            int a = primes[i];
            int b = primes[j];
            if(isValid(a, b)) {
                graph[a].pb(b);
                graph[b].pb(a);
            }
        }
    }
}


void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    dis[node] = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int child : graph[current]) {
            if(!visited[child]) {
                visited[child] = true;
                dis[child] = dis[current] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, a, b;
    cin >> t;

    buildGraph();

    while (t--) {
        cin >> a >> b;

        for(int i = 1000; i <= 9999; i++) {
            visited[i] = false;
            dis[i] = -1;
        }

        bfs(a);

        if(dis[b] == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << dis[b] << endl;
        }
    }

    return 0;
}
