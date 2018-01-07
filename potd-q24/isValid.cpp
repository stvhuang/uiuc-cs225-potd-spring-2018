#include <stack>
#include <string>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    int l = input.length();

    for (int i = 0; i < l; ++i) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            st.push(input[i]);
        } else if (input[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return false;
            }
        } else if (input[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                return false;
            }
        } else if (input[i] == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                return false;
            }
        }
    }

    if (st.empty()) {
        return true;
    } else {
        return false;
    }
}
