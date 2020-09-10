#include <bits/stdc++.h>
using namespace std;

int used[200][200];
int choice[4][2] = {{-1, 0}, {0, -1}, {1, 0},{0, 1}};

bool dfs(int x, int y, int step, vector<vector<char>>& board, string word) {
    if(word[step] != board[x][y] || used[x][y] == 1)
        return false;
    else if(step == word.length()-1)  // 如果长度满足
        return true;
    used[x][y] = 1;  // 设置访问状态
    for(int i=0; i<4; i++) {
        int tmp_x = x + choice[i][0];
        int tmp_y = y + choice[i][1];
        if(0 <= tmp_x && tmp_x < board.size() && 0 <= tmp_y && tmp_y < board[0].size() && dfs(tmp_x, tmp_y, step+1, board, word))
            return true;
    }
    used[x][y] = 0;  // 取消访问状态
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(dfs(i, j, 0, board, word)) 
                return true;
        }
    }
    return false;
}

int main() {
    string word = "aabaaaabbb";
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // vector<vector<char>> board = {{'a', 'a'}};
    vector<vector<char>> board = {{'a','a', 'a'},{'a','b','b'},{'a','b','b'},{'b','b','b'},{'b','b','b'},{'a','a','a'},{'b','b','b'},{'a','b','b'},{'a','a','b'},{'a','b','a'}};
    if (exist(board, word)) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    return 0;
}