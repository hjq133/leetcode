#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 0;
    int x_cur, y_cur, area = 1;
    int choice[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i=0; i<4; i++) {
        x_cur = (x + choice[i][0]);
        y_cur = (y + choice[i][1]);
        if(x_cur >= 0 && y_cur >= 0 && x_cur < grid.size() && y_cur < grid[0].size() && grid[x_cur][y_cur] == 1) {
            area +=  dfs(grid, x_cur, y_cur);
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
    }
    return max_area;
}

int main() {

}