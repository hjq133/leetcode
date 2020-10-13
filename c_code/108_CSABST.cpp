#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& nums, int left, int right) {
    if(left > right) return NULL;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = createTree(nums, left, mid-1);
    root->right = createTree(nums, mid+1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return createTree(nums, 0, nums.size()-1);
}