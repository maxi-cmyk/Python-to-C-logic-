#linked_list 
#two_pointer algo with sentinel (dummy) node

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = prev = ListNode(0)
        dummy.next = head
        
        while head and head.next:
            #dupe
            if head.val == head.next.val:
                #keep going if more dupes
                while head and head.next and head.val == head.next.val:
                    head = head.next
                head = head.next
                prev.next = head
            #no dupes
            else: 
                prev = prev.next
                head = head.next
        return dummy.next