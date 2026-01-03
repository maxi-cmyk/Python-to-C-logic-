#linked_list
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional 

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

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

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Helper: Convert a Python List to a Linked List
def build_list(arr):
    if not arr: return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

# Helper: Convert a Linked List back to a Python List for easy comparison
def list_to_arr(head):
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    return arr

def test_delete_duplicates():
    sol = Solution()

    # Case 1: Standard duplicates [1, 1, 2]
    head1 = build_list([1, 1, 2])
    result1 = sol.deleteDuplicates(head1)
    assert list_to_arr(result1) == [1, 2]

    # Case 2: Multiple duplicates [1, 1, 2, 3, 3]
    head2 = build_list([1, 1, 2, 3, 3])
    result2 = sol.deleteDuplicates(head2)
    assert list_to_arr(result2) == [1, 2, 3]

    # Case 3: All elements are the same [1, 1, 1]
    head3 = build_list([1, 1, 1])
    result3 = sol.deleteDuplicates(head3)
    assert list_to_arr(result3) == [1]

    # Case 4: No duplicates [1, 2, 3]
    head4 = build_list([1, 2, 3])
    result4 = sol.deleteDuplicates(head4)
    assert list_to_arr(result4) == [1, 2, 3]

    # Case 5: Empty List
    head5 = build_list([])
    result5 = sol.deleteDuplicates(head5)
    assert list_to_arr(result5) == []

    print("✅ All Python test cases passed!")

if __name__ == "__main__":
    test_delete_duplicates()