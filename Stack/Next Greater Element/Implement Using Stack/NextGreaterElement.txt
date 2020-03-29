
#include <bits/stdc++.h>
using namespace std;

void NextGreaterElement(int *arr, int n) {
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            cout << arr[i] << " --- " << arr[st.top()] << endl;
        } else {
            cout << arr[i] << " --- " << "-1" << endl;
        }
        st.push(i);
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    NextGreaterElement(arr, n);
}
