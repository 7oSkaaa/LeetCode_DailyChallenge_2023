//Author: Sara Hamza

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        bool cin = 0;
        string sum = "";
        //make sure a is -> the shortest string
        if(n > m)
            swap(a, b), swap(n, m);


        /*

           let b = ----------------------- len = m
               a =             ----------- len = n

                   |--part 2--|--part 1--|
        */

        //add part 1:
        //using full adder eq
        int i = n - 1, j = m - 1;
        while(i >= 0){
            bool x = a[i] == '1', y = b[j] == '1';

            sum = to_string((x^y)^cin) + sum;
            cin = (x&y) | (cin&(x^y));

            --i, --j;
        }

        //add part 2
        //half adder eq
        while(j >= 0){
            bool y = b[j] - '0';
            sum = to_string(y^cin) + sum;
            cin = y&cin;
            --j;
        }
        if(cin)
            sum = "1" + sum;

        return sum;

    }
};
