/** Quick Sort **/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int A[MAX];

int partition(int low, int high) {
    int i = low + 1;
    int j = high;
    int temp;

    while(1) {
        while((i <= high) && (A[i] < A[low])) {
            i++;
        }

        while((j >= (low + 1)) && (A[j] >= A[low])) {
            j--;
        }

        if(i < j)
            swap(A[i], A[j]);
        else
            break;
    }

    swap(A[low], A[j]);
    return j;
}

void quickSort(int low, int high) {
    if(low < high) {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
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

    quickSort(0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

}

