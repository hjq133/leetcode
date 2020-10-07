#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void transpose(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = i + 1; j < matrix[i].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rowReverse(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0, k = matrix[i].size() - 1; j < k; j++, k --) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    rowReverse(matrix);
}

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7, 8, 9}};
    rotate(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}