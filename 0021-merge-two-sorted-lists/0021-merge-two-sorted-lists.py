# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def getFS(l1, l2):
    if(l1.val <= l2.val):
        return l1,l2
    else:
        return l2,l1

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if(not list1): return list2
        if(not list2): return list1

        first, second = getFS(list1, list2)

        head = first # This is for sure.

        prev = None

        while(first and second):
            if(first.val <= second.val):
                prev = first
                first = first.next
            else:
                prev.next = second
                prev = second
                second = second.next
                prev.next = first

        # So, now either first is NULL or second in NULL
        if(not first):
            prev.next = second
        else:
            pass

        return head

