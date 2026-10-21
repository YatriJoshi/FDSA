#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If operand, add to output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If '(', push to stack
        else if (c == '(')
            st.push('(');

        // If ')', pop from stack to output until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Pop the '('
        }

        // Operator encountered
        else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators from stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string expression = "(3+4)*2";
    cout << "Infix Expression: " << expression << "\n";
    cout << "Postfix Expression: " << infixToPostfix(expression) << "\n";
    return 0;
}