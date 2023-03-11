# Author: Lobna Mazhar

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Following this equation 2(a + b) = a + b + c + b
        # Use 2 pointers, one moving slow (node by node) and the other is moving fast (2 nodes per move)
        slow, fast = head, head
        while fast and fast.next:
            # Move the pointers to the next nodes slow and fast
            slow, fast = slow.next, fast.next.next
            # If the 2 pointers meet, this is intersection point
            if slow is fast:
                # Intersection Point, starting from the head, keep moving with 2 new pointers until they meet again, as the distance from the head to cycle start point is equal to the distance from the intersection point to the cycle start point
                start = head
                while start != slow:
                    start, slow = start.next, slow.next
                # When the 2 pointers start and slow meets, then it's the cycle starting point
                return start
        # If the pointers didn't meet, then there is no cycle
        return None


    def detectCycleOld(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Make a dictionary for the existing nodes, used to track visited nodes
        nodes = {}
        # Traverse the linked list until reaching a null node
        while head:
            # If the current node was traversed before, here starts the cycle, return the current node
            if head in nodes: return head
            # If it is the first time for the node to appear, add it to nodes dictionary, and move to the next node
            nodes[head] = ""
            head = head.next
        # Return the current node which will be None as if there were a cycle, the cycle start node will be returned from inside the loop
        return head