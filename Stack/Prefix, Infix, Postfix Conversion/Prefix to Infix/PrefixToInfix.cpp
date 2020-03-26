/* Prefix to Infix Conversion */

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
}

string preToInfix(string str) {
    int length = str.length();
    stack<string> stack;

    for(int i = length - 1; i >= 0; i--) {
        if(isOperator(str[i])) {
            string a = stack.top();
            stack.pop();
            string b = stack.top();
            stack.pop();

            string c = "(" + a + str[i] + b + ")";
            stack.push(c);
        } else {
            stack.push(string(1,str[i]));
        }
    }

    return stack.top();
}

int main() {
    string str;
    cin >> str;
    cout << "Infix: " << preToInfix(str) << endl;

    return 0;
}