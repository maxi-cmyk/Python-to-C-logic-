#linked_list

from typing import Optional 

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        #two pointers, one fast one slow, iterate until both at same spot

        fast = head 
        slow = head 

        while fast and fast.next:
            fast = fast.next.next 
            slow = slow.next 

            if fast == slow:
                return True 
        return False