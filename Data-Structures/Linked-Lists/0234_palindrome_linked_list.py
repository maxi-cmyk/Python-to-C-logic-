#linked_list 
from typing import Optional 

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
       #reverse back half
       #floyd's cycle algo, two pointers, one travel twice as fast
        slow, fast, prev = head, head, None 

        while fast and fast.next: 
            slow, fast = slow.next, fast.next.next #traverse slow to mid and fast to end pt

        while slow: 
            slow.next, prev, slow = prev, slow, slow.next #reversing 
        fast, slow = head, prev #reset from the right half  

        while slow: 
            if fast.val != slow.val:
                return False  
            fast, slow = fast.next, slow.next #increment one step from the back and one step to the back
        return True
        


        