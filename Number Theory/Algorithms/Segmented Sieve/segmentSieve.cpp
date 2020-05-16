#include <bits/stdc++.h>
#define max 32000
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define lli long long int
#define endl '\n'
#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define InputArray(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define CopyArray(a,temp,n) for(int i=0;i<n;i++) temp[i]=a[i];
#define PrintArray(a,n) for(int i=0;i<n;i++) cout << a[i] << " "; cout << endl;
using namespace std;

vi Primes;
vi segPrimes;

void sieve() {
    bool isPrime[max];
    for (int i = 0; i <= max; i++) {
        isPrime[i] = true;
    }

    for (int i = 3; i * i <= max; i += 2) {
        if(isPrime[i]) {
            for (int j = i * i; j < max; j += i) {
                isPrime[j] = false;
            }
        }
    }

    Primes.push_back(2);
    for (int i = 3; i <= max; i += 2) {
        if(isPrime[i]) {
            Primes.push_back(i);
        }
    }
}


void segmentedSieve(lli l, lli r) {
    int size = r - l + 1;
    bool isPrime[size];
    for (int i = 0; i < size; i++) {
        isPrime[i] = true;
    }
    if(l == 1)
        isPrime[0] = false;

    for (int i = 0; Primes[i] * (lli) Primes[i] <= r; i++) {
        int currentPrime = Primes[i];

        // Just smaler or equal value to l
        lli base = (l / currentPrime) * currentPrime;
        if(base < l) {
            base += currentPrime;
        }

        // Mark all multiples within L to R as false
        for (lli j = base; j <= r; j += currentPrime) {
            isPrime[j - l] = false;
        }

        // There may be a case where base is itself a prime number 
        if(base == currentPrime) {
            isPrime[base - l] = true;
        }
    }

    for (int i = 0; i < size; i++) {
        if(isPrime[i]) {
            //cout << (i + l) << endl;
            segPrimes.push_back(i + l);
        }
    }
    puts("");
}

int main() {
#ifndef Niloy
    read("input.txt");
    write("output.txt");
#endif

    sieve();
    int t;
    cin >> t;
    while(t--) {
        lli l, r;
        cin >> l >> r;
        segmentedSieve(l, r);
        for (int i = 0; i <= segPrimes.size() - 1; i++) {
            cout << segPrimes[i] << endl;
        }
    }
    cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
    return 0;
}