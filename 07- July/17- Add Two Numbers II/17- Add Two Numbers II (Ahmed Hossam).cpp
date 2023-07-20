// Author: Ahmed Hossam

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create two stacks to store the digits of l1 and l2
        stack < int > s1, s2;
        
        // Push digits of l1 into stack s1
        while (l1 != NULL)
            s1.push(l1 -> val), l1 = l1 -> next;
        
        // Push digits of l2 into stack s2
        while (l2 != NULL)
            s2.push(l2 -> val), l2 = l2 -> next;
        
        // Create a dummy node as the head of the resulting linked list
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        
        // Perform addition digit by digit until both stacks and carry are empty
        while (!s1.empty() || !s2.empty() || carry) {
            int first = 0, second = 0;
            
            // Get the top digit from stack s1 if it is not empty
            if (!s1.empty())
                first = s1.top(), s1.pop();
            
            // Get the top digit from stack s2 if it is not empty
            if (!s2.empty())
                second = s2.top(), s2.pop();
            
            // Calculate the sum of the digits including the carry
            int sum = carry + first + second;
            carry = sum / 10;
            
            // Create a new node with the digit and attach it to the resulting linked list
            ListNode* attach = new ListNode(sum % 10);
            attach -> next = dummy -> next;
            dummy -> next = attach;
        }
        
        // Return the head of the resulting linked list
        return dummy->next;
    }
};
