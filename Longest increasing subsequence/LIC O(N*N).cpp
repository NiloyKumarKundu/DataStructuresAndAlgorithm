#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> const &a) {
	int n = a.size();
	vector<int> d(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if(a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	int ans = d[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, d[i]);
	}

	return ans;
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif

	vector<int> a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		a.push_back(s);
	}

	int length = lis(a);
	cout << length << "\n";

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}