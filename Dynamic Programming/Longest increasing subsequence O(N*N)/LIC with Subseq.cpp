// Time Complixity -> O(N * N)

#include <bits/stdc++.h>
using namespace std;

vector<int> lis(vector<int> const &a) {
	int n = a.size();
	vector<int> d(n, 1), p(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if(a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}

	int ans = d[0], pos = 0;
	for (int i = 1; i < n; i++) {
		if(d[i] > ans) {
			ans = d[i];
			pos = i;
		}
	}

	vector<int> subset;
	while(pos != -1) {
		subset.push_back(a[pos]);
		pos = p[pos];
	}
	reverse(subset.begin(), subset.end());

	return subset;
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

	vector<int> subset = lis(a);

	for (int i = 0; i < subset.size(); i++) {
		cout << subset[i] << " ";
	}
	cout << endl;

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}