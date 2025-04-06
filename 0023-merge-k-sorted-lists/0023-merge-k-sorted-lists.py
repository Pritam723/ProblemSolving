# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq

class HeapNode:
    def __init__(self, Node):
        self.Node = Node

    def __lt__(self, other):
        if(self.Node.val <= other.Node.val):
            return True
        else:
            return False

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ansHead = ListNode(-1)
        ansTail = ansHead

        n = len(lists)
        
        L = []
        heapq.heapify(L)

        for i in range(n):
            head = lists[i]
            if(head is None):
                continue
            
            heapq.heappush(L, HeapNode(head))

        while(len(L) > 0):
            x = heapq.heappop(L)
            # print(x.Node.val)
            ansTail.next = x.Node
            ansTail = ansTail.next

            # Now, we need to push in Heap too.
            newNode = x.Node.next
            if(newNode):
                heapq.heappush(L, HeapNode(newNode))


        return ansHead.next