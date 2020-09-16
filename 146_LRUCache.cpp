#include <bits/stdc++.h>
using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    private:
        unordered_map<int, DLinkedNode*> m;
        DLinkedNode* dummyHead = new DLinkedNode();
        DLinkedNode* dummyTail = new DLinkedNode();
        int capacity;
        int size;
    public:
        LRUCache(int _capacity) {
            capacity = _capacity;
            size = 0;
            dummyHead->next = dummyTail;
            dummyTail->prev = dummyHead;
        }

        int get(int key) {
            int value = -1;
            if(m.find(key) != m.end()) {   // 存在这个key
                DLinkedNode* ptr = m[key];
                moveToHead(ptr);
                value =  ptr->value;
            }
            return value;
        }

        void put(int key, int value) {
            if(m.find(key) != m.end()) {   // 存在这个key
                DLinkedNode* ptr = m[key];
                ptr->value = value; // 更新value
                moveToHead(ptr);
            }else {  // 不存在这个key，重新添加一个Node
                if(size == capacity) {
                    removeTail();
                    size--;
                }
                DLinkedNode* ptr = new DLinkedNode(key, value);
                m.insert(pair<int, DLinkedNode*>(key, ptr));
                addToHead(ptr);
                size++;
            }
        }

        void moveToHead(DLinkedNode* ptr) {
            // 首先要删除这个节点，然后再把它加到头节点去
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            addToHead(ptr);
        }

        void addToHead(DLinkedNode* ptr) {
            ptr->next = dummyHead->next;
            ptr->prev = dummyHead;
            ptr->next->prev = ptr;
            dummyHead->next = ptr;
        }

        void removeTail() {
            DLinkedNode* tmp = dummyTail->prev;
            dummyTail->prev = dummyTail->prev->prev;
            dummyTail->prev->next = dummyTail;
            m.erase(tmp->key); // 从map中移除这个键
            // free(tmp); // free了会出错.....
        }
};

int main() {
    LRUCache* ccache = new LRUCache(2);
    LRUCache cache = *ccache;
    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得关键字 2 作废
    cout<<cache.get(2)<<endl;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得关键字 1 作废
    cout<<cache.get(1)<<endl;       // 返回 -1 (未找到)
    cout<<cache.get(3)<<endl;       // 返回  3
    cout<<cache.get(4)<<endl;       // 返回  4
    cout<<"end"<<endl;
    return 0;
}