#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<vector<Node*>> res;
void pre_order(Node* root, int depth) {
    if(root == NULL) return;
    if(res.size() <= depth) res.push_back(vector<Node*>());
    pre_order(root->left, depth+1);
    res[depth].push_back(root);
    pre_order(root->right, depth+1);
}

Node* connect(Node* root) {
    pre_order(root, 0);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size()-1; j++) {
            res[i][j]->next = res[i][j+1];
        }
    }
    return root;
}

int main() {
    vector<int> hh;
    cout<<res.size()<<endl;
    return 0;
}