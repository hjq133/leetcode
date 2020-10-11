#include <bits/stdc++.h>
using namespace std;
// 构造环形链表
struct List{
    int val;
    List* next;
    List(int x) : val(x), next(nullptr) {}
};

// 构造一个链表，先把指针用数组存起来
List* createList(vector<int> a) {
    List* tmp[a.size() + 1];
    for(int i=0; i<a.size(); i++)
        tmp[i] = new List(a[i]);
    for(int i=0; i<a.size()-1; i++)
        tmp[i]->next = tmp[i+1];
    return tmp[0];
}

int main() {
    vector<int> a = {1, 9, 8, 3, 10, 21, 222};
    List* lst = createList(a);
}