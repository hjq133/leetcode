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

vector<int> res;

int partition(int begin, int end) {
    int pivot = res[begin];
    while(begin < end) {
        while(begin < end && res[end] >= pivot)
            end--;
        res[begin] = res[end];
        while(begin < end && res[begin] <= pivot)
            begin++;
        res[end] = res[begin];
    }
    res[begin] = pivot;
    return begin;
}

int find_k(int k) {
    int begin=0, end=res.size()-1;
    while(1) {
        int mid = partition(begin, end);
        if(mid == k) return res[k];
        else if(mid > k) {
            end = mid - 1;
        }else {
            begin = mid + 1;
        }
    }
}

void mid_order(TreeNode* root) {
    if(root == NULL) return;
    mid_order(root->left);
    res.push_back(root->val);
    mid_order(root->right);
}

int kthSmallest(TreeNode* root, int k) {
    mid_order(root);
    return find_k(k-1);  // 第k小的数，下标是k-1
}