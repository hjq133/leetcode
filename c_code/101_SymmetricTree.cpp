#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true; // 两个都为NULL
    if(p == NULL || q == NULL) return false; // 一个为NULL，一个不为NULL
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return check(root->left, root->right);
}

int main() {

}