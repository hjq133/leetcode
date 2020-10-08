# TODO 排序链表 O(n log n)
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def find_mid(head):
    slow = head
    fast = head
    previous = None
    while fast is not None and fast.next is not None:
        previous = slow
        slow = slow.next
        fast = fast.next.next
    previous.next = None
    return head, slow


def merge(part1, part2):
    if part1 is None:
        return part2
    if part2 is None:
        return part1
    if part1.val < part2.val:
        part1.next = merge(part1.next, part2)
        return part1
    else:
        part2.next = merge(part1, part2.next)
        return part2


def merge_sort(head):
    if head.next is None:
        return head
    part1, part2 = find_mid(head)
    part1 = merge_sort(part1)
    part2 = merge_sort(part2)
    head = merge(part1, part2)
    return head


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is not None:
            head = merge_sort(head)
        return head


h = ListNode(1)
h.next = ListNode(8)
h.next.next = ListNode(5)
h.next.next.next = ListNode(3)
h.next.next.next.next = ListNode(2)
h.next.next.next.next.next = ListNode(-2)
s = Solution()
h = s.sortList(h)
while h is not None:
    print(h.val)
    h = h.next
print('done')
