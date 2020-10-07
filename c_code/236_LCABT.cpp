#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这个函数只会返回4个值：要么p，要么q，要么nullptr，要么最终结果。
// 并且如果返回的不是最终结果，则一定有left或right为nullptr
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q || root ==nullptr) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);  // 递归左子树和右子树
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;  // 如果p和q都存在，则返回公共祖先
    else if(left) return left;
    else if(right) return right;
    else return nullptr;
}

int main() {

}