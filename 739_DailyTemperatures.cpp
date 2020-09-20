#include <bits/stdc++.h>
using namespace std;

// 这题主要就是找到每个数右边第一个比它大的数
// 所以利用单调递减栈
struct node {
    int id;
    int val;
    node(int _id, int _val) : id(_id), val(_val) {}
};

vector<int> dailyTemperatures(vector<int>& T) {
    stack<node> st;
    vector<int> dis(T.size());
    for(int i=0; i<T.size(); i++) {
        while(!st.empty() && T[i] > st.top().val) {
            dis[st.top().id] = i - st.top().id; 
            st.pop();
        }
        st.push(node(i, T[i]));
    }
    return dis;
}

int main() {

}