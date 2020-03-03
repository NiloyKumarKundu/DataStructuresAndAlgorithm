/** Counting Sort **/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int A[MAX];

void countSort(int n, int k) {
    int count[k + 1];
    int b[n];
    memset(count, 0, sizeof(count));
    //memset(b, 0, sizeof(b));
    for(int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    for(int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        b[--count[A[i]]] = A[i];
    }

    for(int i = 0; i < n; i++) {
        A[i] = b[i];
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    int max = A[0];
    for(int i = 1; i < n; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }

    countSort(n, max);

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}