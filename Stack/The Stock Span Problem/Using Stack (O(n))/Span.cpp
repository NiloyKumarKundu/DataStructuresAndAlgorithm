// Using stack - Time complixity O(n)

#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int price[], int n, int s[]) {
    stack<int> stack;
    stack.push(0);
    s[0] = 1;

    for(int i = 1; i < n; i++) {
        while(!stack.empty() && (price[stack.top()] <= price[i]))
            stack.pop();

        if(stack.empty())
            s[i] = i + 1;
        else
            s[i] = i - stack.top();

        stack.push(i);
    }
}


void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


int main() {
    int n;
    cin >> n;
    int price[n], s[n];
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    calculateSpan(price, n, s);
    printArray(s, n);
    return 0;
}