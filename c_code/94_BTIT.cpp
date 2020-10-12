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

// 递归版本
vector<int> inorderTraversal(TreeNode* root) {
    mid_order(root);
    return res;
}

// 非递归版本 （迭代版本）
vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* stack[100];
    vector<int> res;
    TreeNode* p = root;
    int top = -1;
    if(root != NULL) {
        do {
            for(; p != NULL; p=p->left)
                stack[++top] = p;
            p = stack[top--];  // 弹栈的时候访问p
            res.push_back(p->val);  // visit p
            p = p->right;
        }while(p != NULL || top != -1);
    }
    return res;
}
