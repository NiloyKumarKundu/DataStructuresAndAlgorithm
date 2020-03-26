// Postfix to Prefix Conversion

#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postToPre(string postfix) {
    stack<string> stack;
    int length = postfix.length();

    for(int i = 0; i < length; i++) {
        if(isOperator(postfix[i])) {
            string op1 = stack.top();
            stack.pop();
            string op2 = stack.top();
            stack.pop();

            string temp = postfix[i] + (op2 + op1);
            stack.push(temp);
        } else {
            stack.push(string(1, postfix[i]));
        }
    }
    return stack.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << postToPre(postfix) << endl;

    return 0;
}