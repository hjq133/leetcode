# TODO 最长公共子序列
# TODO 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度
# 转移方程： if str1[i] == str2[j], dp[i][j] = dp[i-1][j-1] + 1
#           else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
# class Solution:
#     def longestCommonSubsequence(self, text1: str, text2: str) -> int:
#         dp = [[] for i in range(len(text2))]
#         for j in range(len(text2)):
#             if text2[i] ==
#         for i in range(len(text1)):
#             for j in range(len(text2)):
#                 i
