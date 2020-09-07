#include<bits/stdc++.h>
using namespace std;
// 滑动窗口类题目
// 解法2，使用unoderset，找到最长长度
// set用于在O(1) 时间内进行查询
// left 和 i 分别表示着队列的队头、队尾
int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    unordered_set<char> lookup;
    int maxStr = 0;
    int left = 0;
    for(int i=0; i < s.size(); i++) {  // 遍历字符集，不断入队
        while(lookup.find(s[i]) != lookup.end()) {  // set里已经存在最新入队的元素, 则进入循环
            lookup.erase(s[left]);
            left++;  // 不断删除元素，直到满足不存在重复字符为止
        }
        maxStr = max(maxStr, i-left+1);  // 更新最长长度
        lookup.insert(s[i]);  // 入队
    }
    return maxStr;
}

int main() {
       string ss = "abcabcac";
       int maxLen = lengthOfLongestSubstring(ss);
       cout<< maxLen <<endl;
       return 0;
}