#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1e9
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define endl '\n'
using namespace std;
/* ----------------------------------------------------------------------------------- */

#define fastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define all(x) x.begin(), x.end()
#define scan(a) scanf("%d", &a)
#define scanll(a) scanf("%lld", &a)
#define scanD(a) scanf("%lf", &a)
#define print(a) printf("%d\n", a)
#define printll(a) printf("%lld\n", a)
#define printD(a) printf("%lf\n", a)
#define printTwo(a) printf("%.2lf\n", a);
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define inputArray(a,n) rep(i, 0, n) cin >> a[i];
#define copyArray(a,temp,n) rep(i, 0, n) temp[i]=a[i];
#define printArray(a,n) rep(i, 0, n) cout << a[i] << " "; cout << endl;

/* ----------------------------------------------------------------------------------- */

#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define showTime cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';

#define dbgA2(A, n, m) {cout<<"--> "<<#A<<" = \n";rep(i, 0, n){rep(j, 0, n){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n) {cout<<" --> "<<#A<<" = (";rep(i, 0, n)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...) {string sss(#args);sss+=',';cout<<" --> ";debugger::call(all(sss), args);cout<<"\n";}

/* ----------------------------------------------------------------------------------- */

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }

struct debugger {
	typedef string::iterator si;
	static void call(si it, si ed) {}
	template<typename T, typename ... aT>
	static void call(si it, si ed, T a, aT... rest) {
		string b;
		for(; *it!=','; ++it)
			if(*it!=' ')
				b+=*it;
		cout << b << "=" << a << " ";
		call(++it, ed, rest...);
	}
};

/* ----------------------------------------------------------------------------------- */


void solve() {
	int n;
	scan(n);
	int arr[n];

	rep(i, 0, n) {
		scan(arr[i]);
	}

	// Prefix sum
	rep(i, 1, n) {
		arr[i] += arr[i - 1];
	}

	int q;
	printf("Enter query time:\n");
	scan(q);
	while(q--) {
		printf("Enter the numbers you want to find the sum:\n");
		int a, b;
		scan(a), scan(b);
		if(a == 0) {
			print(arr[b]);
		} else {
			print(arr[b] - arr[a - 1]);
		}
	}
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif

	solve();

	// __test {
	// 	solve();
	// }

	showTime;
	return 0;
}


