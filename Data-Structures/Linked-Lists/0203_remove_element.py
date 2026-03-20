#linked_list 

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: Optional[ListNode]
        :type val: int
        :rtype: Optional[ListNode]
        """
        #if dummy.val = val, remove 
        ans = ListNode(0, head)
        dummy = ans

        while dummy: 
            while dummy.next and dummy.next.val == val:
                dummy.next = dummy.next.next 
            dummy = dummy.next 
            
        return ans.next