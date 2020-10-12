#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int used[10];

void print() {
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
}

void dfs(int n, int m) {
    if(res.size() == m) {
        print();
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!used[i]) {
            used[i] = 1;
            res.push_back(i);
            dfs(n, m);
            res.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    dfs(n, m);
}