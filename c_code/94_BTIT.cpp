#include <bits/stdc++.h>
using namespace std;

vector<int> res;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void mid_order(TreeNode* root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    res.push_back(root->val);
    inorderTraversal(root->right);
} 

vector<int> inorderTraversal(TreeNode* root) {
    mid_order(root);
    return res;
}