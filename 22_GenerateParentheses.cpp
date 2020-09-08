#include <bits/stdc++.h>
using namespace std;
shared_ptr<vector<string>> cache[100] = {nullptr};

vector<string> generateParenthesis(int n) {
    if (cache[n] != nullptr)
        return *cache[n];
    if (n == 0) {
        cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
    } else {
        auto result = shared_ptr<vector<string>>(new vector<string>);
        for (int i=0; i<n; i++) {
            auto lefts = generate(i);
            auto rights = generate(n-i-1);
            for (const string& left : *lefts)
                for(const string& right : *rights)
                    result -> push_back("(" + left + ")" + right);
        }
    }
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}