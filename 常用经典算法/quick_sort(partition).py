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


def quick_sort(lst, begin, end):
    if begin >= end:
        return
    mid = partition(lst, begin, end)
    quick_sort(lst, begin, mid - 1)
    quick_sort(lst, mid + 1, end)


lst1 = [11, 3, -4, 10, 100, -99, -1000]
quick_sort(lst1, 0, len(lst1) - 1)
print(lst1)
