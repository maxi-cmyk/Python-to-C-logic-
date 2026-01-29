#linked_list 

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        #make two heads, each with one ptr and traverse to target 
        #after traversing both, coonect end of slist to start of blist
        #returm slist.next

        slist, blist = ListNode(), ListNode()
        small, big = slist, blist

        while head:
            if head.val < x:
                small.next = head
                small = small.next
            else:
                big.next = head
                big = big.next
            head = head.next

        small.next = blist.next
        #must poin to NULL otherwise infinite loop
        big.next = None

        return slist.next