#include<bits/stdc++.h>
using namespace std;

// 删除倒数第n个节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* a = dummyHead;
    ListNode* b = dummyHead;
    for(int i=0; i<=n; i++) {
        a = a->next;
    }
    while(a != NULL) {
        a = a->next;
        b = b->next;
    }
    b->next = b->next->next;
    return dummyHead->next;
}