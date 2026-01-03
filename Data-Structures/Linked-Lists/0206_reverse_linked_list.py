#linked_list
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        
        while curr:
            next_node = curr.next  # 1. Save the rest of the list (temp)
            curr.next = prev       # 2. Reverse the pointer (flip)
            
            # 3. Move the window forward
            prev = curr            # Move prev to current
            curr = next_node       # Move current to next
            
        return prev  #prev will be the new head

        