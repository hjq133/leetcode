#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> vis;
    while(head != nullptr) {
        if(vis.count(head)) {
            return head;
        }
        vis.insert(head);
        head = head->next;
    }
    return nullptr;
}

int main() {

}