#linked_list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        #move last element to first 
        if not head or not head.next or k == 0:
            return head
        length = 1
        dummy = head
        while dummy.next: #find length first
            dummy = dummy.next
            length += 1

        k = k % length
        if k == 0:
            return head

        current = head
        for _ in range(length - k - 1):
            current = current.next #connect everything up till k-1
            
        new_head = current.next
        current.next = None #new tail 
        dummy.next = head #connect end of the original list to original start

        return new_head