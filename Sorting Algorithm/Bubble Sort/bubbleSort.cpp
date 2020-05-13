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

int arr[max];

void bubbleSort(int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {  
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);  
        }
    }
} 


int main() {
#ifndef Niloy
    read("input.txt");
    write("output.txt");
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(n);
    PrintArray(arr, n);
    cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
    return 0;
}