// Author: Eslam Ezzat

// Time Complexity: O(N)


// Space Complexity: O(1)

public class Solution
{
    public int MinFlipsMonoIncr(string s)
    {
        int sz = s.Length, counter = 0, mn = 0;

        // sz variable is used to store the size of the string

        // counter variable is used to store the number of zeros

        // mn variable is used to store the number of elements to make the string increase.

        for (int i = 0; i < sz; i++) // iterate through the string 
        {
            if (s[i] == '0')
                counter++; // count the number of zeros
        }

        mn = counter;
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '0')
                mn = Math.Min(mn, --counter);
            else
                counter++;
        }

        return mn;
    }
}