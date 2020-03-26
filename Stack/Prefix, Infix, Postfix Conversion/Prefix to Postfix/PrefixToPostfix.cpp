// Prefix to Postfix
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToPostfix(string prefix) {
    stack<string> stack;

    int length = prefix.length();

    for(int i = length - 1; i >= 0; i--) {
        if(isOperator(prefix[i])) {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();

            string temp = op1 + op2 + prefix[i];
            stack.push(temp);
        } else {
            stack.push(string(1, prefix[i]));
        }
    }

    return stack.top();
}


int main() {
    string str = "*-A/BC-/AKL";
    cout << prefixToPostfix(str) << endl;
}