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

// Linear search start

bool linearSearch(int n) {
    for (int i = 0; i < Numbers.size(); i++) {
        if(Numbers[i] == n) {
            return true;
        }
    }
    return false;
}
// Linear search end


// Binary search start

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
// Binary search end


int main() {
#ifndef Niloy
    read("input.txt");
    write("output.txt");
#endif

    int n, x, result;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int value = rand() % n;
        Numbers.push_back(value);
    }

    // Please comment out one by one and run it to see the proper time of each function

    // for binary search array must be sorted otherwise comment the sort part
    sort(Numbers.begin(), Numbers.end());  

    double start = clock();

    // result = linearSearch(x);               // for 1000000 test case, it took around 0.579438 sec
    // result = binarySearch(x);                  // for 1000000 test case, it took around only 3 milliSec!

    double end = clock();

    if(result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    PrintArray(Numbers, n);

    double time = end - start;
    cerr << time << " milliSec" << endl;
    cerr << time/CLOCKS_PER_SEC << " Sec" << endl;

    return 0;
}

