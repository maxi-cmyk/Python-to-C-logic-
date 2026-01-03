#linked_list 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head) #initialise with zero, and dummy.next points to head 
        prev = dummy 
        curr = head

        while curr and curr.next:
            np = curr.next.next #np is the next pair after current pair 
            second = curr.next #second node of current pair 

            second.next = curr #swap 1 -> 2 to 2 -> 1 
            curr.next = np #connect swapped pair to rest of list 
            prev.next = second 

            prev = curr #move to next pair 
            curr = np 
        return dummy.next 
        