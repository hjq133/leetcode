# TODO 注意这是找第k小的代码 0 <= k <= len - 1
# TODO 如果找第k大，partition符号换一下就ok了


def partition(lst, begin, end):
    pivot = lst[begin]
    while begin < end:
        while begin < end and lst[end] >= pivot:
            end -= 1
        lst[begin] = lst[end]
        while begin < end and lst[begin] <= pivot:
            begin += 1
        lst[end] = lst[begin]
    lst[begin] = pivot
    return begin


def find_kth(k, lst, begin, end):
    mid = partition(lst, begin, end)
    if mid == k:
        return lst[mid]
    elif mid > k:
        return find_kth(k, lst, begin, mid - 1)
    else:
        return find_kth(k, lst, mid + 1, end)


lst1 = [11, 3, -4, 10, 100, -99, -1000]

i = 0  # 0 <= i <= len - 1
res = find_kth(len(lst1) - 1 - i, lst1, 0, len(lst1) - 1)  # 找第i小
print(res)
res = find_kth(i, lst1, 0, len(lst1) - 1)  # 找第i大
print(res)
