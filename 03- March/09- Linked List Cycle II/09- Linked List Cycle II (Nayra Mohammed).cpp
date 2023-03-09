//Author: Nayra Mohammed 

class Solution
{
public:
    /*
        - Just traverse through linked list nodes starting from head.
        - for every visited node we store it in a hash map or set.
        - If current node found to be visited before then this node is our cycle'starting node
        - Otherwise we visited all nodes only once, then there is no cycle. 
    */
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> s; // to know whether a node was visited before or not
       
        while (head)// traverse through linked list till reaching a null node.
        {
            if (s.find(head) != s.end())// if current node was visited before,then it's our answer
                return head;

            s.insert(head); // make current node visited
            head = head->next; // go to current's next node.
        }

        return NULL; // we finished traversing without meeting any cycle
    }
};
