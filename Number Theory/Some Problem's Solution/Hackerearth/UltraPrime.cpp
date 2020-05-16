#include <bits/stdc++.h>
#define max 1000002
#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
 
int sum(int a) {
    int sum = 0;
    while(a) {
        sum += (a % 10);
        a = a / 10;
    }
    return sum;
}
 
 
void sieve(vector<int> &Prime) {
    vector<int> isPrime(max, 1);
 
 
    // Sieve
    for (int i = 2; i * i <= max; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= max; j += i) {
                isPrime[j] = 0;
            }
        }
    }
 
    // Store primes in Prime vector
    for(int i=2; i<=1000000; i++) {
        if(isPrime[i] != 0 && isPrime[sum(i)] != 0)
            Prime.push_back(i);
    }
}
 
 
int main() {
#ifdef Niloy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FastInput;
    vector<int> Prime;
    sieve(Prime);
    int l, r, t;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        int low = lower_bound(Prime.begin(), Prime.end(), l) - Prime.begin();
        int high = lower_bound(Prime.begin(), Prime.end(), r) - Prime.begin();
        if(Prime[high] > r)
            high -= 1;
        cout << (high - low) + 1 << endl;
    }
    return 0;
} 