// Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{

public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> ans; // to store our answer

        int rem = 0; // to store the reminder of adding two digits with result > 9

        // start iterating from the right-most digit
        for (int i = sz(num) - 1, val; i >= 0; i--)
        {   
            // add current digit from num to the current last digit of k 
            // we also add the reminder of previous adding operation
            val = num[i] + (k % 10) + rem;
            
            k /= 10;// remove last digit

            ans.push_back(val % 10);//take only the last digit of the calculated value "avoid vals > 9"

            //if val <=9  then rem will equal to 0 otherwise, we take val with deleting its right-most digit  
            rem = val / 10; 
        }

        /* 
            In case of adding all digits from num and there exists a reminder or k still have digits
            then, its like the previous operation but with leading zeros in num
        */ 

        while (k || rem)
        {
            int val = (k % 10) + rem; // add last digit from k to our reminder

            k /= 10; // remove last digit

            //doin' same operation we ve done before OwO
            ans.push_back(val % 10);
            rem = val / 10;
        }

        reverse(ans.begin(), ans.end()); // reverse answer to make it in a proper form

        return ans;
    }
};
