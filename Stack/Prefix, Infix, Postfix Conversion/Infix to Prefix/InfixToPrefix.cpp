// Infix to Prefix
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char c) {
    if (c == '-' || c == '+')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;

    return 0;
}

string infixToPostfix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> stack;
    string output;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            stack.push('(');
        else if (infix[i] == ')') {
            while (stack.top() != '(') {
                output += stack.top();
                stack.pop();
            }
            stack.pop();
        } else {
            if (isOperator(stack.top())) {
                while (getPriority(infix[i]) < getPriority(stack.top())) {
                    output += stack.top();
                    stack.pop();
                }
                stack.push(infix[i]);
            }
        }
    }
    return output;
}

string infixToPrefix(string infix) {
    int l = infix.size();
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string s = {"K+L-M*N+(O^P)*W/U/V*T+Q"};
    cout << "Infix notation is: " <<  infixToPrefix(s) << endl;
}