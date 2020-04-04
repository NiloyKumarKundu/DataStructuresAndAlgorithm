#include <bits/stdc++.h>
#define size 4
using namespace std;

int q[size + 1];
int F = 0, R = 0;

void enqueue(int item) {
    int s = (R + 1) % (size + 1);
    if (F == s)
        cout << "queue full" << endl;
    else {
        R = s;
        q[R] = item;
    }
}

void dequeue() {
    if (F == R) {
        cout << "queue empty" << endl;
    } else {
        F = (F + 1) % (size + 1);
    }
}

void print() {
    if(F == R)
        cout << "queue empty" << endl;
    else {
        int i = (F + 1) % (size + 1);
        while(1) {
            cout << q[i] << endl;
            i = (i + 1) % (size + 1);
            if(i == R) {
                break;
            }
        }
    }
}


int main() {
    enqueue(10);
    print();

}