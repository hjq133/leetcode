#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pre_order(TreeNode* root, int depth, vector<vector<int>>& res) {
    if(root == NULL) return;
    if(depth >= res.size()) res.push_back({});
    res[depth].push_back(root->val);
    pre_order(root->left, depth+1, res);
    pre_order(root->right, depth+1, res);
    return;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res(100);
    pre_order(root, 0, res);
    return res;
}

int main() {
    vector<vector<int>> res(100);
    return 0;
}
