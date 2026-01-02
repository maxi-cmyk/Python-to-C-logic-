#linked_list
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #if duplicate, remove duplicate, head.next = head.next.next
        res = head
        while head and head.next: #!= NULL 
            if head.val == head.next.val:
                head.next = head.next.next
            else: 
                head = head.next
        return res
        