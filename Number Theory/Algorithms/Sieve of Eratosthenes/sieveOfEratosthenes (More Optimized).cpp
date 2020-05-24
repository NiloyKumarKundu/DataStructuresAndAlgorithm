#include <bits/stdc++.h>
#define max 10000002
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
vi Primes;

bool getPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return isPrime[n] == true;
}


void sieve() {
    for (int i = 0; i <= max; i++) {
        isPrime[i] = true;
        // Primes.push_back(0);
    }

    for (int i = 3; i * i <= max; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max; j += i)
                isPrime[j] = false;
        }
    }

    Primes.push_back(2);
    for (int i = 3; i < max; i += 2) {
        if(isPrime[i]) {
            Primes.push_back(i);
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
    for (int i = 0; i < 200; i++) {
        cout << Primes[i] << endl;
    }
    
    return 0;
}