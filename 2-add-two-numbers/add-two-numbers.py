# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        t1, t2 = l1, l2
        root = ListNode()
        carry = 0
        v = t1.val + t2.val + carry
        carry = v // 10
        v = v % 10
        root.val = v
        temp = root
        t1 = t1.next
        t2 = t2.next
        while t1 or t2:
            if t1 and t2:
                v = t1.val + t2.val + carry
                carry = v // 10
                v = v % 10
                t = ListNode(val=v)
                temp.next = t
                t1 = t1.next
                t2 = t2.next
                temp = temp.next
            elif t1:
                v = t1.val + carry
                carry = v // 10
                v = v % 10
                t = ListNode(val=v)
                temp.next = t
                t1 = t1.next
                temp = temp.next
            elif t2:
                v = t2.val + carry
                carry = v // 10
                v = v % 10
                t = ListNode(val=v)
                temp.next = t
                t2 = t2.next
                temp = temp.next
        if carry:
            if carry < 10:
                temp.next = ListNode(val=carry)
            else:
                temp.next = ListNode(val=carry % 10)
                temp.next.next = ListNode(val=carry // 10)

        return root
