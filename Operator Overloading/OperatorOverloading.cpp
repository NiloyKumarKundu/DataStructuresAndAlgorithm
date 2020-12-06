#include <bits/stdc++.h>
#define MAX 1e5 + 6
#define MOD 1000000007
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

// scanf()
#define scan(a)			  scanf("%d", &a);
#define scanll(a)		  scanf("%lld", &a);
#define scanD(a)		  scanf("%lf", &a);
#define scan2(a, b)		  scanf("%d %d", &a, &b);
#define scan3(a, b, c)	  scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);

// printf()
#define print(a)		   printf("%d\n", a);
#define printD(a)		   printf("%.9lf\n", a);
#define printTwoD(a)	   printf("%.2lf\n", a);
#define print2(a, b)	   printf("%d %d\n", a, b);
#define print3(a, b, c)	   printf("%d %d %d\n", a, b, c);
#define print4(a, b, c, d) printf("%d %d %d\n", a, b, c, d);
#define printll(a)		   printf("%lld\n", a);

#define read(x)	 freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);

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


int dr[] = {+1, -1, +0, +0};                         // 4 Direction - DOWN, UP, RIGHT, LEFT
int dc[] = {+0, +0, +1, -1};
//int dr[] = {+0, +0, +1, -1, +1, +1, -1, -1};       // 8 Direction - RIGHT, LEFT, DOWN, UP, RIGHT-DOWN, LEFT-DOWN, UP-RIGHT, UP-LEFT
//int dc[] = {+1, -1, +0, +0, +1, -1, +1, -1};
//int dr[] = {-1, +1, -2, -2, -1, +1, +2, +2};       // knight Moves
//int dc[] = {-2, -2, -1, +1, +2, +2, +1, -1};

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

#define Niloy

/* ----------------------------------------------------------------------------------- */


struct node {
	char ch;
	ll value;

	bool operator < (const node &p) const {
		return value > p.value;
	}
};

struct node Node[26];

void solve() {
	ll n, k, Max = 0;
	scanll(n);
	scanll(k);
	string str;
	cin >> str;

	rep(i, 0, 26) {
		Node[i].ch = 'A' + i;
		Node[i].value = 0;
	}

	rep(i, 0, str.size()) {
		int index = str[i] - 'A';
		Node[index].value++;
	}

	sort(Node, Node + 26);
	
	rep(i, 0, 26) {
		cout << Node[i].ch << " " << Node[i].value << endl;
	}
}

int main() {
#ifdef Niloy
	read("input.txt");
	write("output.txt");
#endif
	// fastInput;
	
	solve();

	// __test {
	// 	solve();
	// }
	
	// showTime;
	return 0;
}

 