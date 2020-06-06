#include <bits/stdc++.h>
#define MAX		  1000000
#define pb		  push_back
#define pairs	  pair<int, int>
#define vi		  vector<int>
#define vb		  vector<bool>
#define vii		  vector<pairs>
#define lb		  lower_bound
#define ub		  upper_bound
#define lli		  long long int
#define endl	  '\n'
#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Cases	  cout << "Case " << ++Case << ": ";
#define __test    \
	int tt;       \
	int Case = 0; \
	cin >> tt;    \
	while (tt--)
#define read(x)	 freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define InputArray(a, n)        \
	for (int i = 0; i < n; i++) \
		cin >> a[i];
#define CopyArray(a, temp, n)   \
	for (int i = 0; i < n; i++) \
		temp[i] = a[i];
#define PrintArray(a, n)        \
	for (int i = 0; i < n; i++) \
		cout << a[i] << " ";    \
	cout << endl;
using namespace std;

void printSubSet(int a[], int n, int k) {
	for (int i = 1; i < pow(2, n); i++) {
		vi v;
		int x = i;
		while (x > 0) {
			int z = x % 2;
			v.push_back(z);
			x /= 2;
		}
		int p = n - v.size();
		for (int j = 1; j <= p; j++) {
			v.push_back(0);
		}
		reverse(v.begin(), v.end());

		int count = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == 1) {
				count++;
			}
		}

		if (count == k) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == 1) {
					cout << a[j];
				}
			}
			cout << endl;
		}
		v.clear();
	}
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif

	int n, k;
	cout << "Enter number of elements in array: " << endl;
	cin >> n;
	cout << "Enter number of size of subset: " << endl;
	cin >> k;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	printSubSet(a, n, k);

	return 0;
}