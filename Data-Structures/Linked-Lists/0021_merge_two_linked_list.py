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
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = temp = ListNode()
        while list1 != None and list2 != None:
            if list1.val < list2.val:
                temp.next = list1
                list1 = list1.next
            else: 
                temp.next = list2
                list2 = list2.next
            temp = temp.next #increment temp 
        temp.next = list1 or list2 #add remaining elements 
        return dummy.next
    
# Helper to build a list from an array
def build_list(arr):
    dummy = ListNode(0)
    curr = dummy
    for val in arr:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

# Helper to turn list back into array for comparison
def list_to_arr(head):
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res

def test_merge():
    sol = Solution()
    
    # Case 1: Standard overlapping lists
    l1 = build_list([1, 2, 4])
    l2 = build_list([1, 3, 4])
    assert list_to_arr(sol.mergeTwoLists(l1, l2)) == [1, 1, 2, 3, 4, 4]
    
    # Case 2: One list is empty
    l1 = build_list([])
    l2 = build_list([0])
    assert list_to_arr(sol.mergeTwoLists(l1, l2)) == [0]
    
    # Case 3: Both lists empty
    l1 = build_list([])
    l2 = build_list([])
    assert list_to_arr(sol.mergeTwoLists(l1, l2)) == []
    
    # Case 4: Different lengths
    l1 = build_list([1])
    l2 = build_list([2, 3, 4, 5])
    assert list_to_arr(sol.mergeTwoLists(l1, l2)) == [1, 2, 3, 4, 5]

    print("✅ All Python Merge tests passed!")

test_merge()


        
        