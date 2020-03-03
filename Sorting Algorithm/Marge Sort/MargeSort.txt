/** Marge Sort **/

#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int A[MAX];

void marge(int low, int mid, int high) {
    int l[10], r[10], n1, n2;
    n1 = mid - low + 1;
    n2 = high - mid;

    for(int i = 0; i < n1; i++) {
        l[i] = A[low + i];
    }
    for(int i = 0; i < n2; i++) {
        r[i] = A[mid + i + 1];
    }
    l[n1] = r[n2] = 10000000;
    int i = 0, j = 0;

    for(int k = low; k <= high; k++) {
        if(l[i] <= r[j]) {
            A[k] = l[i];
            i++;
        } else {
            A[k] = r[j];
            j++;
        }
    }
}


void margeSort(int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        margeSort(low, mid);
        margeSort(mid + 1, high);
        marge(low, mid, high);
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

    margeSort(0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}
