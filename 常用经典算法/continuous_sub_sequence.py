# 最大子区间和
# 动态规划
# res[i]表示以i结尾的子序列的最大和


class Solution:
    @staticmethod
    def maxSubArray(nums):
        res = [nums[0]]  # 初始化以nums[0]结尾的数组的最大子序和
        for i in range(1, len(nums)):
            res.append(max(res[i - 1] + nums[i], nums[i]))
        return max(res)


lst = [0, 1, -2, -4, 9, 1, 0]
print(Solution.maxSubArray(lst))
