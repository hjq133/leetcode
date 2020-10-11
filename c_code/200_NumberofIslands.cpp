#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int x, int y) {
    int x_cur, y_cur;
    grid[x][y] = '0';
    int choice[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<4; i++) {
        x_cur = (x + choice[i][0]);
        y_cur = (y + choice[i][1]);
        if(x_cur >= 0 && y_cur >= 0 && x_cur < grid.size() && y_cur < grid[0].size() && grid[x_cur][y_cur] == '1') {
            dfs(grid, x_cur, y_cur);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {    
    int sum = 0;
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            if(grid[i][j] == '1') {
                sum += 1;
                dfs(grid, i, j);
            }
        }
    }
    return sum;
}

int main() {

}