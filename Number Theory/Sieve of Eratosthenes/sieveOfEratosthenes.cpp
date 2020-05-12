#include <bits/stdc++.h>
#define max 90000000
#define maxN 1000000
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

bool isPrime[max];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = 0, isPrime[1] = 0;
    for (int i = 2; i * i <= max; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= max; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int limit = 40;         // Limit joto porjonto lagbe
    for (int i = 1; i < limit; i++) {
        cout << isPrime[i] << endl;
    }
    
    return 0;
}