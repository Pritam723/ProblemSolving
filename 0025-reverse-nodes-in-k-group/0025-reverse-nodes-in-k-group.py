# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def printLL(head):
    t = head
    i = 0
    while(t is not None):
        # print(t.val)
        t = t.next
        i = i + 1
    
    return i

def sol(currHead, k):
    newHead, newTail, nextHead = None, None, None
    prev = None
    forward = None
    newTail = currHead
    curr = currHead
    
    i = 0
    
    while(i < k):
        
        forward = curr.next
        curr.next = prev
        prev = curr
        curr = forward
        
        i = i + 1
        
    newHead = prev
    nextHead = forward
    return (newHead, newTail, nextHead)


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        L = printLL(head)
        # print(L)
        
        prevTail = None
        ans = None
        
        currHead = head
        
        newHead, newTail, nextHead = None, None, None
        while((currHead is not None) and (L >= k)):
            newHead, newTail, nextHead = sol(currHead, k)
            
            # print(newHead.val)
            # print(newTail.val)
            # print(nextHead.val)
            
            
            L = L - k
            currHead = nextHead
            
            if(prevTail is None):
                prevTail = newTail
                ans = newHead
            else:
                prevTail.next = newHead
                prevTail = newTail
            
            # Now after this if currHead is not NULL it means
            # Last part is still detached.
            prevTail.next = nextHead
        
        return ans