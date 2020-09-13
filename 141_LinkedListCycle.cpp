#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// bool hasCycle(ListNode *head) {
//     unordered_map<ListNode *, int> m;
//     while(head != NULL) {
//         if(m.count(head) > 0) {
//             return true;
//         }else {
//             m.insert(pair<ListNode*, int>(head, 1));
//         }
//         head = head->next;
//     }
//     return false;
// }
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> set;
    ListNode* cur = head;
    while(cur != NULL) {
        if(set.count(cur) == 1) return true;
        set.insert(cur);
        cur = cur->next;
    }
    return false;
}
int main() {

}