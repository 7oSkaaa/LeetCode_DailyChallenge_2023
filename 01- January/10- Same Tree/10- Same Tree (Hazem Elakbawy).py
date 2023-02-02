# Author : Hazem Elakbawy

class Solution(object):
    def isSameTree(self, p, q):
        """
        Approach :-
        We traverse through all tree Nodes (root,left,right)
        equal ==> return True 
        else  ==> retun False
        **** Notice :- the order of conditions is important
        """
        def traverse(p,q):
            # check if both nodes are Null
            if not p and not q:
                return True
            # check if only one if Null (after checking if both are Null)
            elif not p or not q:
                return False
            # if none of them are Null then check if they are not equal
            elif p.val!=q.val:
                return False
            # if they are equal then check (left Node) and (right Node)
            return traverse(p.left,q.left) and traverse(p.right,q.right)
            
        return traverse(p,q)






