#linked_list

from typing import Optional 

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        #traverse to left first, swap elements in between right n left, reconnect 
        if (left == right):
            return head
        dummy = ListNode(0, head)
        prev = dummy

        for _ in range(left - 1):
            prev = prev.next
            
        curr = prev.next
        #swap 
        for _ in range(right - left):
            temp = curr.next
            curr.next = temp.next 
            temp.next = prev.next 
            prev.next = temp
        return dummy.next
        