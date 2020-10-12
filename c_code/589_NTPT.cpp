#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 递归算法
// vector<int> res;
// void _preorder(Node* root) {
//     if(root == NULL) return;
//     res.push_back(root->val);
//     for(auto tree: root->children) {
//         preorder(tree);
//     }
// }

// vector<int> preorder(Node* root) {
//     _preorder(root);
//     return res;
// }

// 非递归算法(不会)
// vector<int> preorder(Node* root) {
//     Node* stack[100];
//     vector<int> res;
//     int top = -1;
//     Node* p = root;
//     if(root != NULL) {
//         for(; p != NULL; p=p->left) {

//         }
//     }
//     return res;
// }

int main() {

}