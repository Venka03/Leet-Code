class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


begin = ListNode(1, ListNode(2, ListNode(3, ListNode(1))))
tmp1 = begin
tmp2 = begin
stack = []
while tmp2.next:
    stack.append(tmp1.val)
    tmp1 = tmp1.next
    tmp2 = tmp2.next
    if tmp2.next:
        tmp2 = tmp2.next
print(stack)
print(tmp2.val)