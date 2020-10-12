#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 非递归的遍历
vector<int> preorderTraversal(TreeNode* root) {
    TreeNode* stack[100], * p = root;
    int top = -1;
    vector<int> res;
    if(root != NULL) {
        do{
            for(; p!=NULL; p=p->left) {
                stack[++top] = p;
                res.push_back(p->val); // 入栈的时候访问p
            }
            p = stack[top--];
            p = p->right;
        }while(p != NULL || top != -1);
    }
    return res;
}

// 递归遍历
vector<int> rres;
void preorder(TreeNode* root) {
    if(root == NULL) return ;
    rres.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    preorder(root);
    return rres;
}
