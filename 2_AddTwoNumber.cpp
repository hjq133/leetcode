#include<bits/stdc++.h>
using namespace std;
// 将代码提交到leetcode时注意将 (ListNode*)malloc(sizeof(ListNode)); 替换为 new ListNode();
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int flag = 0;
    ListNode *t3 = (ListNode*)malloc(sizeof(ListNode));  // 开辟空间，leetcode中用new ListNode()
    ListNode* res = t3;
    while(t1 != NULL || t2 != NULL || flag) {  // flag 表示进位
        if(t1 != NULL) {
            t3->val += t1->val;
            t1 = t1->next;
        }
        if(t2 != NULL) {
            t3->val += t2->val;
            t2 = t2->next;
        }
        if(flag) {
            t3->val += 1;
        }
        if(t3->val >= 10) {
            t3->val -= 10;
            flag = 1;
        } else {
            flag = 0;
        }
        if(t1 != NULL || t2 != NULL || flag) {
            t3->next = (ListNode*)malloc(sizeof(ListNode));
            t3 = t3->next;
        }
    }
    return res;
}

// 辅助函数，向列表里添加值
void add(ListNode* l, int val) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->next = NULL;
    tmp->val = val;
    while(l->next != NULL) {
        l = l->next;
    }
    l->next = tmp;
}

int main() {
    ListNode* t1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode* t2 = (ListNode *)malloc(sizeof(ListNode));
    t1->val = 2;
    t2->val = 5;
    add(t1, 4);
    add(t1, 3);
    add(t2, 6);
    add(t2, 4);
    ListNode* res = addTwoNumbers(t1, t2);
    cout<<"------------"<<endl;
    while(res != NULL) {
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}