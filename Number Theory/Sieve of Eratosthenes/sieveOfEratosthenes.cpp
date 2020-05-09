#include <bits/stdc++.h>
#define max 1000000
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

int isPrime[max];

bool getPrimes(int n) {
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    return isPrime[n] == 1;
}

void sieve() {
    for (int i = 1; i <= max; i++) {
        isPrime[i] = 1;
    }

    isPrime[0] = isPrime[1] = 0;

    for (int i = 3; i * i <= max; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= max; j += i + i) {
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

    int t;
    cin >> t;
    sieve();
    while(t--) {
        int n;
        cin >> n;
        if(getPrimes(n)) {
            cout << "Prime" << endl;
        } else {
            cout << "Not Prime!" << endl;
        }
    }

    return 0;
}
