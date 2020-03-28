#include <bits/stdc++.h>
using namespace std;

void NextGreaterElement(int *arr, int n) {
    int next;
    for(int i = 0; i < n; i++) {
        next = -1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --- " << next << endl;
    }
}


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    NextGreaterElement(a, n);
}
