# TODO 判断两个链表是否相交
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# 判断两个链表是否相交，不相交则返回None
# TODO 如果不相交，两个指针t1和t2最终走到头，同时等于None，此时退出循环，返回None
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        t1 = headA
        t2 = headB
        while t1 != t2:
            t1 = headB if t1 is None else t1.next
            t2 = headA if t2 is None else t2.next
        return t1
