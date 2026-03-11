#linked_list
#concatenation trick, swap tracks 

#O(N+M) time complexity, O(1) space 

from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        listA = headA
        listB = headB 

        while listA != listB: 
            #switch to the other list so that the difference in length btwn both lists is neutralised
            if listA:
                listA = listA.next
            else: 
                listA = headB
            if listB: 
                listB = listB.next 
            else: 
                listB = headA
        return listA
    
# --- TEST HELPER FUNCTION ---
def run_test(name, valsA, valsB, skipA, skipB):
    """
    Builds two linked lists that intersect.
    valsA, valsB: Lists of values for the linked lists.
    skipA, skipB: The index where the intersection begins.
    """
    # Create dummy heads
    dummyA = ListNode(0)
    dummyB = ListNode(0)
    currA, currB = dummyA, dummyB
    
    # 1. Build the separate initial parts
    for i in range(skipA):
        currA.next = ListNode(valsA[i])
        currA = currA.next
        
    for i in range(skipB):
        currB.next = ListNode(valsB[i])
        currB = currB.next
        
    # 2. Build the shared intersection part
    intersection_node = None
    if skipA < len(valsA) and skipB < len(valsB):
        # Create the first shared node
        intersection_node = ListNode(valsA[skipA])
        currA.next = intersection_node
        currB.next = intersection_node
        curr = intersection_node
        
        # Add the rest of the shared nodes
        for i in range(skipA + 1, len(valsA)):
            curr.next = ListNode(valsA[i])
            curr = curr.next

    # 3. Run the solution
    sol = Solution()
    result = sol.getIntersectionNode(dummyA.next, dummyB.next)
    
    # 4. Print results
    print(f"--- {name} ---")
    if result:
        print(f"Intersection at node with value: {result.val}")
    else:
        print("No intersection")
    print()

# --- RUNNING THE TEST CASES ---

# Test Case 1: Standard intersection (Different lengths before merge)
# List A: [4, 1, 8, 4, 5]
# List B: [5, 6, 1, 8, 4, 5]
# Intersects at value '8'
run_test("Test 1: Standard Intersection", 
         valsA=[4, 1, 8, 4, 5], 
         valsB=[5, 6, 1, 8, 4, 5], 
         skipA=2, skipB=3)

# Test Case 2: No intersection at all
# List A: [2, 6, 4]
# List B: [1, 5]
run_test("Test 2: No Intersection", 
         valsA=[2, 6, 4], 
         valsB=[1, 5], 
         skipA=3, skipB=2)

# Test Case 3: Exact same length before intersection
# List A: [1, 2, 3]
# List B: [4, 5, 3]
# Intersects at '3'
run_test("Test 3: Same Length Intersection", 
         valsA=[1, 2, 3], 
         valsB=[4, 5, 3], 
         skipA=2, skipB=2)