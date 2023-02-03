# Author: Lobna Mazhar

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # If the length of the string is less than 4 or more than 12 (3 * 4), then it can't form an IP Address
        if(len(s)) < 4 or len(s) > 12: return []
        
        res = set()
        self.makeAddress(s, len(s), [], 4, 0, res)
        return res

    def makeAddress(self, s, length, values, remaining_points, current_index, res):
        # If no more remaining_points to add, check if the whole string was used, then add the values to the final result
        if remaining_points == 0:
            if length == 0: res.add('.'.join(values))
            return

        ####### IGNORE THOSE 2 LINES FOR NOW ######
        # min_possible_size = length // remaining_points
        # max_value_size = min(3, min_possible_size + length % remaining_points)

        # Starting with a minimum of 1 character to a maximum of 3 character per IP slot:
        for i in range(1, 4):
            # Check if the value is a valid IP address part
            value = s[current_index:current_index + i]
            if self.isValid(value):
                # If valid value, continue making the address by decreasing the remaining length by the length of the current value, add the current value to the values list, decreasing the remaining_points and incrementing the index to start after taking the current value
                self.makeAddress(s, length - i, values + [value], remaining_points - 1, current_index + i, res)

    # Check if the given value is a valid IP Address slot
    def isValid(self, value:str) -> bool:
        # Length should be within 0 and 3
        if len(value) == 0 or len(value) > 3: return False
        # Value can't start with leading zeros
        if len(value) > 1 and value[0] is '0': return False
        # Int value should be with 0 and 255 inclusive
        return 0 <= int(value) <= 255
