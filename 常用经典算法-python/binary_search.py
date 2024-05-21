'''
binary search
lowest bound
'''

def binarySearch(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    if len(nums) == 0:
        return -1

    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    # End Condition: left > right
    return -1

def lowerBound(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    找到最后一个小于target的数
    """
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    # End Condition: left > right
    # End 之后，right是第一个小于target的数，left是第一个大于等于target的数
    return right