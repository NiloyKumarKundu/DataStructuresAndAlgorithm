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

bool isPrime(int n) {
    if(n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifndef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(isPrime(n)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
