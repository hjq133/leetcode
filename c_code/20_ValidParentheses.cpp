#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<int> st;
    char cc;
    for(auto ch : s) {
        if(ch == '{' || ch == '(' || ch == '[') {
            st.push(ch);
        } else {
            if(st.empty())
                return false;
           cc = st.top();
           if( !((cc == '(' && ch == ')') || (cc == '[' && ch == ']') || (cc == '{' && ch == '}')) )
               return false;
           st.pop();
        }
    }
    return st.empty();
}

int main() {

}