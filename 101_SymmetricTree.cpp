#include <bits/stdc++.h>
using namespace std;

vector<int> res;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void mid_order_fix(TreeNode* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right != NULL)
        root->left = new TreeNode(-1);
    else if(root->left != NULL && root->right == NULL)
        root->right = new TreeNode(-1);
    else {
        mid_order_fix(root->left);
        mid_order_fix(root->right);
    }
}

void mid_order(TreeNode* root) {
    if(root == NULL)
        return;
    mid_order(root->left);
    res.push_back(root->val);
    mid_order(root->right);
}

bool isSymmetric(TreeNode* root) {
    mid_order_fix(root);
    mid_order(root);
    bool flag = true;
    for(int i=0, j=res.size()-1; i<j; i++, j--) {
        if(res[i] != res[j]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {

}