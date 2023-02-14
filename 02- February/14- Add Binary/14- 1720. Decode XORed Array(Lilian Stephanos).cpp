// Author : Lilian Stephanos
class Solution {
public:
/*
Approach : 
We can find all the elements one by one with the help of a      
(first elements), and to find the next element i.e b       
we have to xor a by arr[0], similarly for c       
xor arr[1] with b and so on.
This works by following the properties of XOR as stated below:  
1_XOR of a number to itself is zero.
2_XOR of a number with zero given the number itself.
ai ^ arr[i] = ai ^ ai ^ ai+1
            = 0 ^ ai+1
            = ai+1
*/
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size()+1 ;
        vector<int> vc(n);
        vc[0] = first ;
        for (int i = 1; i < n; i++)
        {
            vc[i] = vc[i-1]^encoded[i-1];
        }
        return vc ;
    }
};