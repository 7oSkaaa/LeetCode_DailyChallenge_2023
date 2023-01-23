# Author: Lobna Mazhar

class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        # Initialize a dictionary for the parents where each character is his own parent
        parents = {c:c for c in string.ascii_lowercase}

        # For each character from the 2 strings get the 2 parents and compare them to each other
        for i in range(len(s1)):
            p1, p2 = self.getParent(s1[i], parents), self.getParent(s2[i], parents)

            # If the 2 parents don't match, update the larger parent with the other as a new parent to keep the parents as the smaller characters
            if p1 != p2:
                if p1 < p2: self.updateParent(s2[i], p1, parents)
                else: self.updateParent(s1[i], p2, parents)
        
        # Using the resulted parents dictionary, build the equivalent lexicographically string for the given baseStr by getting each parent for each character
        res = []
        for i in range(len(baseStr)): res.append(self.getParent(baseStr[i], parents))

        return ''.join(res)
    
    # Get the parent of the given character
    def getParent(self, value: str, parents: dict) -> str:
        while parents[value] != value:
            parents[value] = parents[parents[value]]
            value = parents[value]
        return value
    
    # Update parent for the given character to match the new parent and update its ancestors to match the new parent
    def updateParent(self, value, parent, parents):
        while value != parents[value]:
            parents[value], value = parent, parents[value]
        parents[value] = parent




