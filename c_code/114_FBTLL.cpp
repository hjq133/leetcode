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

vector<TreeNode*> res;

void pre_order(TreeNode* root) {
    if(root == NULL) return ;
    res.push_back(root);
    pre_order(root->left);
    pre_order(root->right);
}

void flatten(TreeNode* root) {
    if(root == NULL) return;
    pre_order(root);
    int i;
    for(i=0; i<res.size()-1; i++) {
        res[i]->left = NULL;
        res[i]->right = res[i+1];
    }
    res[i]->left = NULL;
    res[i]->right = NULL;
}

int main() {

}
