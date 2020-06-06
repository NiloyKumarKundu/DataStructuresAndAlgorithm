#include <bits/stdc++.h>
#define max		  1000000
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

vi subset;
int n;

void search(int k) {
	if (k == n + 1) {
		// process subset
		return;
	} else {
		// include k in the subset
		subset.push_back(k);
		search(k + 1);
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		subset.pop_back();
		cout << endl;
		// don’t include k in the subset
		search(k + 1);
	}
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif

	cin >> n;
	search(1);
	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}