'''
You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

Example 1:
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place.

Example 2:
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
'''

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    @classmethod
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        nodeA = list1
        for i in range(a-1):
            nodeA = nodeA.next
        nodeB = nodeA
        for i in range(a-1, b+1):
            nodeB = nodeB.next
        nodeA.next = list2
        while nodeA.next:
            nodeA = nodeA.next
        nodeA.next = nodeB
        return list1

def printLinkedList(lst: ListNode):
    while lst:
        print(lst.val, end=' ')
        lst = lst.next
    print()


l1 = ListNode(10, ListNode(1, ListNode(13, ListNode(6, ListNode(9, ListNode(5))))))
l2 = ListNode(1000000, ListNode(1000001, ListNode(1000002)))
l1 = Solution.mergeInBetween(l1, 3, 4, l2)
printLinkedList(l1)

l1 = ListNode(0, ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, ListNode(6)))))))
l2 = ListNode(1000000, ListNode(1000001, ListNode(1000002, ListNode(1000003, ListNode(1000004)))))
l1 = Solution.mergeInBetween(l1, 2, 5, l2)
printLinkedList(l1)