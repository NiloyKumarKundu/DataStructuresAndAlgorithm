#include <bits/stdc++.h>
#define MAX 100000
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
#define PrintArray(a,n) for(int i=0;i<=n;i++) cout << a[i] << " "; cout << endl;
using namespace std;

int fib[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int f;
		if (i <= 2) {
			f = 1;
		} else {
			f = fib[i - 1] + fib[i - 2];
		}
		fib[i] = f;
	}

	cout << fib[n] << endl;

	PrintArray(fib, n);

	cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
	return 0;
}