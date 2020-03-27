#include<bits/stdc++.h>
using namespace std;

bool areParanthesisBalanced(string str) {
    stack<char> st;
    char x;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
            continue;
        }

        if(st.empty())
            return false;

        if(str[i] == ')') {
            x = st.top();
            st.pop();
            if(x == '{' || x == '[')
                return false;
        } else if(str[i] == '}') {
            x = st.top();
            st.pop();
            if(x == '(' || x == '[')
                return false;
        } else if(str[i] == ']') {
            x = st.top();
            st.pop();
            if(x == '(' || x == '{')
                return false;
        }
    }
    return (st.empty());
}



int main() {
    string str;
    getline(cin, str);

    if (areParanthesisBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}