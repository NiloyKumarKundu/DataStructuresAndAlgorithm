// Time Complixity O(N*N)

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

int LCS(int n, int m) {
	if(a[n] == '\0' || b[m] == '\0') {
		return 0;
	}
	if(a[n + 1] == b[m + 1]) {
		return 1 + LCS(n + 1, m + 1);
	} else {
		return max(LCS(n, m + 1), LCS(n + 1, m));
	}
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif
	cin >> a >> b;
	int result = LCS(0, 0);
	cout << result << endl;

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}