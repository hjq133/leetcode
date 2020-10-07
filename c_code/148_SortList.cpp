#include <bits/stdc++.h>
using namespace std;

// Tips: 链表找中点：快慢指针！
// Tips: 链表nlogn排序：归并排序
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* previous = NULL;
    while(fast != NULL && fast->next != NULL) {  // 不可能出现只有一个节点的情况
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // 把链表分成两个部分
    previous->next = NULL;
    return slow;
}

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val < l2->val) {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }else {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
}

ListNode* mergeSort(ListNode* head) {
    if(head->next == NULL) return head;
    ListNode* mid = findMid(head);
    ListNode* l1 = mergeSort(head);
    ListNode* l2 = mergeSort(mid);
    return mergeTwoList(l1, l2);
}

ListNode* sortList(ListNode* head) {
    return (head == NULL) ? NULL: mergeSort(head);
}