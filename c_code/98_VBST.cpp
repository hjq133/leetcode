#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> res;
void mid_order(TreeNode* root) {
    if(root == NULL)
        return;
    mid_order(root->left);
    res.push_back(root->val);
    mid_order(root->right);
}

bool isValidBST(TreeNode* root) {
    mid_order(root);
    for(int i=0; (i+1)<res.size(); i++) {
        if(res[i] >= res[i+1])
            return false;
    }
    return true;
}

int main() {
    TreeNode* root = NULL;
    if(isValidBST(root)) {
        cout<<"true"<<endl;
    }else {
        cout<<"false"<<endl;
    }
    return 0;
}