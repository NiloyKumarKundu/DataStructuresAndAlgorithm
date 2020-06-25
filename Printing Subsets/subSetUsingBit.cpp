#include <bits/stdc++.h>
#define MAX 1000000
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

#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define all(x) x.begin(), x.end()
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

vector<vector<int>> TwoD;

void print(vi subset) {
	for (int i = 0; i < subset.size(); i++) {
		cout << subset[i] << " ";
	}
	cout << endl;
}

void printTwoD() {
	for (int i = 0; i < TwoD.size(); i++) {
		cout << "[";
		for (int j = 0; j < TwoD[i].size(); j++) {
			cout << TwoD[i][j];
			if(j != TwoD[i].size() - 1) {
				cout << ", ";
			}
		}
		if(i != TwoD[i].size() - 1) {
			cout << "]," << endl;
		} else {
			cout << "]" << endl;
		}
	}
}


void solve() {
	int n;
	cin >> n;
	int arr[10];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < (1 << n); i++) {
		vi subset;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				subset.push_back(arr[j]);
		}
		TwoD.push_back(subset);
	}
}

int main() {
	solve();
	printTwoD();

	// __test {
	// 	solve();
	// }
}