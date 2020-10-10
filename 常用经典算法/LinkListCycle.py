# TODO 判断是否有环的代码
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return False
        fast = head.next.next
        slow = head.next
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False
