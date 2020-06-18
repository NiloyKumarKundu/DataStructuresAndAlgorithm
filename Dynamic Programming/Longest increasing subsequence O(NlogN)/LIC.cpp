#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> const &a) {
	int n = a.size();
	const int INF = 1e9;
	vector<int> d(n + 1, INF);
	d[0] = -INF;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if(d[j - 1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
		}
	}

	int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
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

	int subset = lis(a);
	cout << subset << endl;

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}
