#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0) return NULL;
    int i;
    for(i=0; i<inorder.size(); i++) {
        if(inorder[i] == preorder[0]) break;  //在inorder中找到根节点，然后进行划分左子树和右子树
    }
    TreeNode* root = new TreeNode(inorder[i]);
    int left_len = i; // 左子树长度
    int right_len = preorder.size()-i-1; // 右子树长度
    if(left_len >= 1) {  // 左边可以成树
        vector<int> left_preorder(preorder.begin()+1, preorder.begin()+i+1);  // 创建[begin, end)区间的
        vector<int> left_inorder(inorder.begin(), inorder.begin()+i);  // 创建[begin, end)区间的
        root->left = buildTree(left_preorder, left_inorder);
    }
    if(right_len >= 1) {
        vector<int> right_preorder(preorder.begin()+i+1, preorder.end());  // 创建[begin, end)区间的
        vector<int> right_inorder(inorder.begin()+i+1, inorder.end());  // 创建[begin, end)区间的
        root->right = buildTree(right_preorder, right_inorder);
    }
    return root;
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder ={9,3,15,20,7};
    TreeNode* res = buildTree(preorder, inorder);
    return 0;
}