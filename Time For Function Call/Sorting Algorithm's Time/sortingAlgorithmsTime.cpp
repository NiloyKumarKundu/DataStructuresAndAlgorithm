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

int Numbers[max];

// Count Sort Start

void countSort(int n, int k) {
    int count[k + 1];
    int b[n];
    memset(count, 0, sizeof(count));
    //memset(b, 0, sizeof(b));
    for(int i = 0; i < n; i++) {
        count[Numbers[i]]++;
    }

    for(int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        b[--count[Numbers[i]]] = Numbers[i];
    }

    for(int i = 0; i < n; i++) {
        Numbers[i] = b[i];
    }
}
// Count Sort end



// Marge sort Start

void marge(int low, int mid, int high) {
    int l[1000000], r[1000000], n1, n2;
    n1 = mid - low + 1;
    n2 = high - mid;

    for(int i = 0; i < n1; i++) {
        l[i] = Numbers[low + i];
    }
    for(int i = 0; i < n2; i++) {
        r[i] = Numbers[mid + i + 1];
    }
    l[n1] = r[n2] = 10000000;
    int i = 0, j = 0;

    for(int k = low; k <= high; k++) {
        if(l[i] <= r[j]) {
            Numbers[k] = l[i];
            i++;
        } else {
            Numbers[k] = r[j];
            j++;
        }
    }
}


void margeSort(int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        margeSort(low, mid);
        margeSort(mid + 1, high);
        marge(low, mid, high);
    }
}
// Marge sort end



// Quick sort start

int partition(int low, int high) {
    int i = low + 1;
    int j = high;
    int temp;

    while(1) {
        while((i <= high) && (Numbers[i] < Numbers[low])) {
            i++;
        }

        while((j >= (low + 1)) && (Numbers[j] >= Numbers[low])) {
            j--;
        }

        if(i < j)
            swap(Numbers[i], Numbers[j]);
        else
            break;
    }

    swap(Numbers[low], Numbers[j]);
    return j;
}

void quickSort(int low, int high) {
    if(low < high) {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}
// Quick sort end



// Bubble sort start

void bubbleSort(int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {  
            if (Numbers[j] > Numbers[j+1])
                swap(Numbers[j], Numbers[j+1]);  
        }
    }
}
// Bubble sort end 




int main() {
#ifndef Niloy
    read("input.txt");
    write("output.txt");
#endif

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value = rand() % 1000000;
        Numbers[i] = value;
    }

    double start = clock();
    // Please comment out one by one and run it to see the proper time of each function

    // bubbleSort(n);              // for same test case it took 60.3955 sec
    // countSort(n, 1000000);      // for 100000 test case it took 0.008694 sec
    // margeSort(0, n - 1);        // for same test case it took 0.01989 sec
    // quickSort(0, n - 1);        // for same test case it took 0.019433 sec

    double end = clock();
    double time = end - start;
    PrintArray(Numbers, n);
    cerr << time << " milliSec" << endl;
    cerr << time/CLOCKS_PER_SEC << " Sec" << endl;

    return 0;
}

/*
    Quick Sort's time complixity in worst case O(n*n);

    - When array is sorted then
    - when the array is reversed
    - when the array is the same values
    - when there are few and unique keys
*/

/*
    Marge Sort's time complixity in worst case is O(nlog(n));
*/

// Counting sort is more powerful between a range