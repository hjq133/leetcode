#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* l3 = res;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val > l2->val) {
            l3->next = l2;
            l2 = l2->next;
        } else {
            l3->next = l1;
            l1 = l1->next;
        }
        l3 = l3->next;
    }
    if(l1 == NULL) {
        l3->next = l2;
    } else {
        l3->next = l1;
    }
    return res->next;
}