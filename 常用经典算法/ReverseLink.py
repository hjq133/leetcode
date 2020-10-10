# 反转链表


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        prev = head
        cur = head.next
        prev.next = None
        while cur is not None:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        return prev


h = ListNode(1)
h.next = ListNode(2)
h.next.next = ListNode(3)
s = Solution()
h = s.reverseList(h)
print('hh')
