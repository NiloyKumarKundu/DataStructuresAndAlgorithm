#include <bits/stdc++.h>
#define max 1000000
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

vi Numbers;


bool binarySearch(int n) {
    int low = 0, high = Numbers.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        // Check if x is present at mid 
        if(Numbers[mid] == n) {
            return true;
        }

         // If x greater, ignore left half 
         if(Numbers[mid] < n) {
             low = mid + 1;
         }

         // If x is smaller, ignore right half 
         else {
             high = mid - 1;
         }
    }

    // if we reach here, then element was 
    // not present
    return false;
}

void PrintNumber(bool result) {
    if(result) {
        cout << "Number exist" << endl;
    } else {
        cout << "Number does not exist" << endl;
    }
}

int main() {
#ifndef Niloy
    read("input.txt");
    write("output.txt");
#endif
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Numbers.pb(x);
    }
    sort(Numbers.begin(), Numbers.end());       // to implement binary search, array must be sorted!
    bool result = binarySearch(k);
    PrintNumber(result);

    cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
    return 0;
}