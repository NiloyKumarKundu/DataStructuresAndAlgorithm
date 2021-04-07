#include <bits/stdc++.h>
using namespace std;
#define INF 100000

void marge(int arr[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[q + i + 1];
	}
	L[n1] = INF;
	R[n2] = INF;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
	}
}

void marge_sort(int arr[], int p, int r) {      
    if (p < r) {
		int q = (p + r) / 2;
		marge_sort(arr, p, q);
		marge_sort(arr, q + 1, r);
		marge(arr, p, q, r);
	}
}


int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	marge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
