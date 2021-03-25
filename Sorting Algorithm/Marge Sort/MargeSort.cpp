#include <bits/stdc++.h>
using namespace std;


void marge(int A[], int p, int q, int r) {
    int L[1000], R[1000], n1, n2;
    n1 = q - p + 1;
    n2 = r - q;

    for(int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[q + i + 1];
    }
    L[n1] = R[n2] = 10000000;
    int i = 0, j = 0;

    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


void margeSort(int A[], int p, int r) {
    int q;
    if(p < r) {
        q = (p + r) / 2;
        margeSort(A, p, q);
        margeSort(A, q + 1, r);
        marge(A, p, q, r);
    }
}


int main() {
    int n;
    cin >> n;
	int A[n];

	for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    margeSort(A, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}
