#include <bits/stdc++.h>
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define lli long long int
#define endl '\n'
#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define InputArray(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define CopyArray(a,temp,n) for(int i=0;i<n;i++) temp[i]=a[i];
#define PrintArray(a,n) for(int i=0;i<n;i++) cout << a[i] << " "; cout << endl;
using namespace std;

string a, b;
int DP[100][100];

int LCS(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if(i == 0 || j == 0) {
				DP[i][j] = 0;
			} else if(a[i - 1] == b[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			} else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	return DP[n][m];
}


void PrintLCS(int n, int m) {
	int index = LCS(n, m);
	char ans[index];

	while(n > 0 && m > 0) {
		if(a[n - 1] == b[m - 1]) {
			ans[index--] = a[n - 1];
			n--;
			m--;
		} else if(DP[n - 1][m] > DP[n][m - 1]) {
			n--;
		} else {
			m--;
		}
	}
	cout << ans << endl;
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif
	cin >> a >> b;
	// int result = LCS(a.length(), b.length());
	// cout << result << endl;
	PrintLCS(a.length(), b.length());

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}