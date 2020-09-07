#include<bits/stdc++.h>
using namespace std;

//解法1，真实模拟队列实现，找到最长队列长度
int q[100000] = {0};  // 开大点
int rear = 0, front = 0, len = 0;

void in(int val) {
    q[rear++] = val;
    len++;
}

char out() {
    char c = q[front++];
    len--;
    return c;
}

int isCharExsit(char c) {
    for(int i=front; i<=rear; i++ ) {
        if(q[i] == c) {
            return 1;
        }
    }
    return 0;
}

int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    for(int i=0; i < s.length(); i++) {
        if(isCharExsit(s[i])) {
            while(s[i] != (out()));
            in(s[i]);
        }else {
            in(s[i]);
        }
        maxLen = maxLen > len ? maxLen : len;
    }
    return maxLen;
}

int main() {
       string ss = "abcabcac";
       int maxLen = lengthOfLongestSubstring(ss);
       cout<< maxLen <<endl;
       return 0;
}