#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int pre_order(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(pre_order(root->left), pre_order(root->right));
}

int maxDepth(TreeNode* root) {
    return pre_order(root);
}

int main() {

}